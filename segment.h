#ifndef SEGMENT_H
#define SEGMENT_H

enum class SegmentState { 
    Intact, 
    Damaged, 
    Destroyed 
};


class ShipSegment {
public:
    ShipSegment();

    SegmentState GetState();

    void ApplyDamage();

private:
    SegmentState state;
};

#endif 