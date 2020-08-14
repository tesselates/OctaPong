#pragma once


namespace pong {


/**
 *  Class that manipulates the position of a ball in the game model
 */
class BallModel {

public:
    /**
     * @param r             the radius of the ball
     */ 
    BallModel(double r);
    BallModel() = default;


    /**
     *  Access methods
     */ 
    double getRadius() const { return r; };
    double getXCoordinate() const { return x; };
    double getYCoordinate() const { return y; };
    double getYVelocity() const { return yV; };
    double getXVelocity() const { return xV; };

    void setXVelocity (double xV) { this->xV = xV; };
    void setYVelocity (double yV) { this->yV = yV; };
    void setXCoordinate(double x) { this->x = x; };
    void setYCoordinate(double y) { this->y = y; };


    /**
     *  Class logic
     */

    /**
     *  Perform an elastic collision with the x-axis
     */ 
    void collideX() { this->xV *= -1; };

    /**
     *  Perform an elastic collision with the y-axis 
     */ 
    void collideY() { this->yV *= -1; };

    /**
     *  Change the position of the ball based on the current velocities
     * 
     *  @param frequency            the frequency indicates with which frequency this method is called, the greater the frequency the smaller the movement
     */ 
    void move(double frequency); 


private:
    double r;  // radius of the ball

    double x;  // x coordinate
    double y;  // y coordinate

    double xV = 0;  // x velocity
    double yV = 0;  // y velocity
};


}  // pong namespace
