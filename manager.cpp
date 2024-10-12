#include <iostream>
#include <vector>

#include "ship.h"
#include "manager.h"



ShipManager::ShipManager( std::vector<int>& shipLengths) {
        for (auto& length : shipLengths) {
            ships.emplace_back(length, false); 
        }
    }

// void ShipManager::SetShipOrientation(int shipIndex, bool isVertical) {
//     if (shipIndex < 0 || shipIndex >= ships.size()) {
//         throw std::out_of_range("Invalid ship index.");
//     }
//     ships[shipIndex].SetOrientation(isVertical); 
// }

void ShipManager::ApplyDamage(int shipIndex, int segmentIndex) {
    if (shipIndex < 0 || shipIndex >= ships.size()) { 
        throw std::out_of_range("Invalid ship index.");
    }
    ships[shipIndex].ApplyDamage(segmentIndex);
}

std::vector<Ship>& ShipManager::GetShips() { return ships; }

bool ShipManager::IsAllShipsDestroyed(){
    for (auto& ship : ships) {
        if (!ship.IsDestroyed()) {
            return false;
        }
    }
    return true;
}
