#pragma once

#include "BallModel.hpp"

namespace pong {

class LifeLine {

public:
    LifeLine(double xLine, int xDirection); 
    LifeLine() = default;

    double getXLine() const { return xLine; };
    double getXDirection() const { return xDirection; };

    void setXLine (double x) { this->xLine = x; };
    void setXDirection (int x) { this->xDirection = x; };
    
    bool testCollision(const BallModel& ball) const;

private:
    double xLine;
    int xDirection;
};


}  // pong namespace
