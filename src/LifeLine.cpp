#include "LifeLine.hpp"


namespace pong {

LifeLine::LifeLine(double xLine, int xDirection) : xLine(xLine), xDirection(xDirection) {}


bool LifeLine::testCollision(const BallModel& ball) const {
    if (xDirection*(ball.getXCoordinate() + xDirection*ball.getRadius()/2) < xDirection*xLine)
    {
        return true; 
    } else {
        return false;
    }   
}


}  // pong namespace
