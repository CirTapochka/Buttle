#include <iostream>
#include <vector>

#include "segment.h"
#include "ship.h"


Ship::Ship(int length, bool isVertical) : length(length), isVertical(isVertical) {
        if (length < 1 || length > 4) {
            throw std::invalid_argument("Invalid ship length.");
        }

        segments.resize(length);
    }

int Ship::GetLength() { return length; }

bool Ship::IsVertical() { return isVertical; }

// void Ship::SetOrientation(bool isVertical) {
//         this->isVertical = isVertical;
//     }

bool Ship::IsDestroyed(){
    for (auto& segment : segments) {
        if (segment.GetState() != SegmentState::Destroyed) {
            return false;
        }
    }
    return true;
}

void Ship::ApplyDamage(int segmentIndex) {
    if (segmentIndex < 0 || segmentIndex >= length) {
        throw std::out_of_range("Invalid segment index.");
    }
    segments[segmentIndex].ApplyDamage();
}

std::vector<ShipSegment>& Ship::GetSegments() { return segments; }

