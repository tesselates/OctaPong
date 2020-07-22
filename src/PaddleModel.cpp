#include "PaddleModel.hpp"


namespace pong {


PaddleModel::PaddleModel() 
{

}

PaddleModel::PaddleModel(double xCoordinate, double yCoordinate) : xCoordinate (xCoordinate), yCoordinate(yCoordinate)
{

}

void PaddleModel::move() {
    this->yCoordinate + yVelocity;
    this->xCoordinate + xVelocity;
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


void PaddleModel::velocity_update() {
    if (this->is_up == true) {
        this->yVelocity -= 5;
    } else if (this->is_down == true) {
        this->yVelocity += 5;
    } 
}


}  // pong namespace
