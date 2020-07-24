#pragma once

#include "BallModel.hpp"

namespace pong {

class LifeLine {

public:
    LifeLine(double xLine, double yLine, double xDirection, double yDirection); 
    LifeLine() = default;

private:
    double xLine;
    double yLine;
    int xDirection;
    int yDirection;

    bool testCollision(const BallModel& ball) const;

    friend class PongModel;
};


}  // pong namespace
