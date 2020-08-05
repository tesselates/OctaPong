#pragma once

#include "BallModel.hpp"


namespace pong {


/**
 *  Class that tests if a ball has crossed a set line
 */ 
class LifeLine {

public:
    /**
     * @param xLine         x-coordinate of the line that indicates where a crossing is detected when the ball passes
     * @param xDirection    the side of the line where the ball may not cross
     */ 
    LifeLine(double xLine, int xDirection); 
    LifeLine() = default;

    /**
     *  Access methods
     */ 
    double getXLine() const { return xLine; };
    double getXDirection() const { return xDirection; };

    void setXLine (double x) { this->xLine = x; };
    void setXDirection (int x) { this->xDirection = x; };
    

    /**
     *  Class logic
     */ 

    /** 
     * Tests if the ball has moved beyond the allowed line
     * 
     * @param ball      the ball that is tested
     */
    bool testCrossing(const BallModel& ball) const;

private:
    double xLine;  // x-coordinate of the line that indicates where a collision is detected when the ball passes
    int xDirection; // indicates the side of the line where the ball may not pass without collision
};


}  // pong namespace
