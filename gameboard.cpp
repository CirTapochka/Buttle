#include <iostream>
#include <vector>

#include "gameboard.h"


GameField::GameField(int width, int height) : width(width), height(height) {
    field.resize(width * height, CellStatus::Unknown);
}

// Конструктор копирования
GameField::GameField(GameField& other) : width(other.width), height(other.height) {
    field.resize(width * height);
    std::copy(other.field.begin(), other.field.end(), field.begin());
}

// Конструктор перемещения
GameField::GameField(GameField&& other) /*noexcept*/ : width(other.width), height(other.height), field(std::move(other.field)) {
    other.width = 0;
    other.height = 0;
}

// Оператор присваивания копированием
GameField& GameField::operator = (GameField& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        field.resize(width * height);
        std::copy(other.field.begin(), other.field.end(), field.begin());
    }
    return *this;
}

// Оператор присваивания перемещением
GameField& GameField::operator=(GameField&& other) /*noexcept*/ {
    if (this != &other) {
        width = other.width;
        height = other.height;
        field = std::move(other.field);
        other.width = 0;
        other.height = 0;
    }
    return *this;
}

void GameField::PlaceShip(Ship& ship, int x, int y, bool isVertical) {
    if (x < 0 || x + (isVertical ? 0 : ship.GetLength()) >= width ||
        y < 0 || y + (isVertical ? ship.GetLength() : 0) >= height) {
        throw std::out_of_range("Ship placement out of bounds.");
    }

    // Проверка на пересечение с другими кораблями
    for (int i = 0; i < ship.GetLength(); i++) {
        int cellX = x + (isVertical ? 0 : i);
        int cellY = y + (isVertical ? i : 0);
        if (GetCellStatus(cellX, cellY) != CellStatus::Unknown) {
            throw std::invalid_argument("Ship collision.");
        }
    }

    // Помещение корабля на поле
    for (int i = 0; i < ship.GetLength(); i++) {
        int cellX = x + (isVertical ? 0 : i);
        int cellY = y + (isVertical ? i : 0);
        field[cellX + cellY * width] = CellStatus::Ship;
    }
}

void GameField::AttackCell(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Invalid cell coordinates.");
    }

    if (GetCellStatus(x, y) == CellStatus::Unknown) {
        field[x + y * width] = CellStatus::Empty;
    } else if (GetCellStatus(x, y) == CellStatus::Ship) {
        int shipIndex = 0;                                      // Повреждение корабля                                   
        int segmentIndex = 0;                                   // Определение индекса корабля и сегмента
        for (auto& ship : shipManager.GetShips()) {
            for (int i = 0; i < ship.GetLength(); i++) {
                int cellX = ship.IsVertical() ? x : y;
                int cellY = ship.IsVertical() ? y : x;
                if (cellX == x && cellY == y) {
                    shipManager.ApplyDamage(shipIndex, i);
                    return;
                }
            }
            shipIndex++;
        }
    }
}

CellStatus GameField::GetCellStatus(int x, int y){
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Invalid cell coordinates.");
    }
    return field[x + y * width];
}

int GameField::GetWidth() { return width; }
int GameField::GetHeight() { return height; }


void GameField::SetShipManager(ShipManager& manager) { // Получение доступа к управлению кораблями
    shipManager = manager;
}


