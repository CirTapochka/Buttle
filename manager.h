#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <vector>

#include "ship.h"

class ShipManager {
public:
    ShipManager(std::vector<int>& shipLengths);
    ShipManager(){}
    void SetShipOrientation(int shipIndex, bool isVertical);
    void ApplyDamage(int shipIndex, int segmentIndex);

    std::vector<Ship>& GetShips();

    bool IsAllShipsDestroyed();

private:
    std::vector<Ship> ships;
};

#endif