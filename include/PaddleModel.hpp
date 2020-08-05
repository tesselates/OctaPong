#pragma once


#include "BallModel.hpp"


namespace pong {

class PaddleModel {

public:
    /**
     * @param width
     * @param length
     */ 
    PaddleModel(double width, double length);
    PaddleModel();


    /**
     *  Access methods
     */ 
    void set_up(bool is_up) { this->is_up = is_up; };
    void set_down(bool is_down) { this->is_down = is_down; };

    double getXCoordinate() const { return x; };
    double getYCoordinate() const { return y; };
    double getWidth() const { return width; }; 
    double getLength() const { return length; }; 

    void setXVelocity (double xV) { this->xV = xV; };
    void setYVelocity (double yV) { this->yV = yV; };
    void setXCoordinate(double x) { this->x = x; };
    void setYCoordinate(double y) { this->y = y; };


    /**
     *  Class logic
     */

    /**
     *  Change the position of the paddle based on the current velocities
     * 
     *  @param frequency            the frequency indicates with which frequency this method is called, the greater the frequency the smaller the movement
     */ 
    void move(double frequency); 

    /**
     *  Adjust the velocity of the paddle based on is_up and is_down variables
     * 
     *  @param frequency            the frequency indicates with which frequency this method is called, the greater the frequency the smaller the velocity adjustment
     */ 
    void velocity_update(double frequency); 

    /**
     *  Tests and performs an elasitc collision with a ball
     *  x-axis collsions also transfer some of the y-velocity of the paddle to that of the ball 
     * 
     * @param ball      the ball that is tested
     */ 
    void enactCollision(BallModel& ball); 

private:
    double width;
    double length;

    double x;  // x coordinate
    double y;  // y coordinate

    double xV = 0;  // x velocity
    double yV = 0;  // y velocity
    
    double yA = 0;  // y acceleration
    double xA = 0;  // x acceleration
    double aM = 0.01;  // the accelartion multiplier, variable indicates how fast the paddle de-accelerates based on its velocity
    double vT = 0.10;  // the minimum velocity before the paddle's velocity hits 0
 
    bool is_up = false;  // indicates if the paddle is gaining velocity upward from external forces
    bool is_down = false;  // indicates if the padlle is gaining velocity downward from external forces


    /**
     * Perform an elasitc y-axis collision with a ball
     *      
     * @param ball      the ball that is tested
     */ 
    void yCollision(BallModel& ball);  

    /**
     *  Perform an elasitc x-axis collision with a ball
     * 
     * @param ball      the ball that is tested
     */ 
    void xCollision(BallModel& ball); 
};


}  // pong namespace
