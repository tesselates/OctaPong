#include "PaddleModel.hpp"
#include <math.h>

namespace pong {


PaddleModel::PaddleModel() 
{

}

PaddleModel::PaddleModel(double xSize, double ySize) : xSize (xSize), ySize(ySize)
{

}

void PaddleModel::move(double frequency) {
    this->yCoordinate += yVelocity/frequency;
    this->xCoordinate += xVelocity/frequency;
    this->yVelocity += this->yAcceleration;
    this->xVelocity += this->xAcceleration;
    if (abs(this->yVelocity) < this->velocity_threshold) {
        this->yVelocity = 0;
    }
    if (abs(this->xVelocity) < this->velocity_threshold) {
        this->xVelocity = 0;
    }
    this->yAcceleration = -this->yVelocity * this->acceleration_multiplier;
    this->xAcceleration = -this->xVelocity * this->acceleration_multiplier;
}


void PaddleModel::velocity_update(double frequency) {
    if (this->is_up == true) {
        this->yVelocity -= 500/frequency;
    } else if (this->is_down == true) {
        this->yVelocity += 500/frequency;
    } 
}

void PaddleModel::enactCollision(BallModel& ball) {

}

}  // pong namespace
