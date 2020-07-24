#include "LifeLine.hpp"


namespace pong {


LifeLine::LifeLine(double xLine, double yLine, double xDirection, double yDirection) :
    xLine(xLine),
    yLine(yLine),
    xDirection(xDirection),
    yDirection(yDirection)
{

}

bool LifeLine::testCollision(const BallModel& ball) const {
    if (xDirection*ball.getXCoordinate() < xDirection*xLine 
        &&
        yDirection*ball.getYCoordinate() < yDirection*yLine) 
    {
        return true; 
    } else {
        return false;
    }   
}


}  // pong namespace
