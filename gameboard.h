#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <vector>

#include "manager.h"

enum class CellStatus { 
    Unknown, 
    Empty, 
    Ship 
};

class GameField {
public:

     GameField(int width, int height);

    GameField(GameField& other);    // Конструктор копирования
    GameField(GameField&& other);    // Конструктор перемещения

    GameField& operator = (GameField& other);    // Оператор присваивания копированием
    GameField& operator = (GameField&& other);    // Оператор присваивания перемещением

    void PlaceShip(Ship& ship, int x, int y, bool isVertical);

    void AttackCell(int x, int y);

    CellStatus GetCellStatus(int x, int y);

    int GetWidth();
    int GetHeight();

    void SetShipManager(ShipManager& manager);     // Получение доступа к управлению кораблями

private:
    int width;
    int height;
    std::vector<CellStatus> field;
    ShipManager shipManager;
};

#endif