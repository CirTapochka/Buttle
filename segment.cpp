#include <iostream>

#include "segment.h"


ShipSegment::ShipSegment() : state(SegmentState::Intact) {}

SegmentState ShipSegment::GetState() { return state; }

void ShipSegment::ApplyDamage() {
    if (state == SegmentState::Intact) {
        state = SegmentState::Damaged;
    } else if (state == SegmentState::Damaged) {
        state = SegmentState::Destroyed;
    }
}

