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
    this->y += yV/frequency;
    this->x += xV/frequency;
    this->yV += this->yA;
    this->xV += this->xA;
    if (abs(this->yV) < this->vT) {
        this->yV = 0;
    }
    if (abs(this->xV) < this->vT) {
        this->xV = 0;
    }
    this->yA = -this->yV * this->aM;
    this->xA = -this->xV * this->aM;
}


void PaddleModel::velocity_update(double frequency) {
    if (this->is_up == true) {
        this->yV -= 500/frequency;
    } else if (this->is_down == true) {
        this->yV += 500/frequency;
    } 
}

void PaddleModel::enactCollision(BallModel& ball) {

}

}  // pong namespace
