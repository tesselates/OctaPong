#include "LifeLine.hpp"


namespace pong {

LifeLine::LifeLine(double xLine, int xDireciotn) : xLine(xLine), xDirection(xDirection) {}


bool LifeLine::testCollision(const BallModel& ball) const {
    if (xDirection*ball.getXCoordinate() < xDirection*xLine)
    {
        return true; 
    } else {
        return false;
    }   
}


}  // pong namespace
