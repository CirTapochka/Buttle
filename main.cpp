#include <iostream>
#include <vector>

#include "manager.h"
#include "gameboard.h"

int main() {
 
    GameField gameField(10, 10);

    
    std::vector<int> shipLengths = { 4, 3, 3, 2, 2 };   // Создание менеджера кораблей
    ShipManager shipManager(shipLengths);

    // Установка кораблей на поле
    gameField.PlaceShip(shipManager.GetShips()[0], 1, 1, true); // Горизонтально
    gameField.PlaceShip(shipManager.GetShips()[1], 3, 0, false); // Вертикально

    // Атака на клетки
    gameField.AttackCell(1, 1);
    gameField.AttackCell(3, 0);
    gameField.AttackCell(3, 1);

    // Проверка состояния кораблей
    if (shipManager.IsAllShipsDestroyed()) {
        std::cout << "Все корабли уничтожены!" << std::endl;
    }

    return 0;
}