#pragma once

#include "BallModel.hpp"

namespace pong {

class LifeLine {

public:
    LifeLine(double xLine, double yLine, double xDirection, double yDirection); 
    LifeLine() = default;

    double getXLine() const { return xLine; };
    double getXDirection() const { return xDirection; };

    void setXLine (double x) { this->xLine = x; };
    void setXDirection (int x) { this->xDirection = x; };
    
private:
    double xLine;
    int xDirection;

    bool testCollision(const BallModel& ball) const;
};


}  // pong namespace
