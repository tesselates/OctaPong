#pragma once

#include "BallModel.hpp"

namespace pong {

class PaddleModel {

public:
    PaddleModel();
    PaddleModel(double xSize, double ySize);

    void set_up(bool is_up) { this->is_up = is_up; };
    void set_down(bool is_down) { this->is_down = is_down; };

    double getXCoordinate() const { return x; };
    double getYCoordinate() const { return y; };
    double getWidth() const { return xSize; }; 
    double getLength() const { return ySize; }; 

    /**
     * moves the player based on the current velocity
     */
    void move(double frequency); 
    void velocity_update(double frequency); 
    void enactCollision(BallModel& ball); 

    void setXVelocity (double xV) { this->xV = xV; };
    void setYVelocity (double yV) { this->yV = yV; };
    void setXCoordinate(double x) { this->x = x; };
    void setYCoordinate(double y) { this->y = y; };

private:
    double xSize;
    double ySize;

    double x;
    double y;

    double xV = 0;
    double yV = 0;
    
    double yA = 0;
    double xA = 0;
    double aM = 0.01;
    double vT = 0.10;

    bool is_up = false;
    bool is_down = false;
};


}  // pong namespace
