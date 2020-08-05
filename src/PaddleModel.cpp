#include "PaddleModel.hpp"
#include "config.hpp"
#include <QDebug>
#include <math.h>
#include <cmath>

#include "utility.hpp"

namespace pong {


PaddleModel::PaddleModel() 
{

}

PaddleModel::PaddleModel(double width, double length) : width (width), length(length)
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
        this->yV -= 10/frequency;
    } else if (this->is_down == true) {
        this->yV += 10/frequency;
    } 
}

void PaddleModel::enactCollision(BallModel& ball) {
    double topy = this->y + length/2;
    double boty = this->y - length/2;
    double leftx = this->x - width/2;
    double rightx = this->x + width/2;
    double xrdis = abs(rightx - ball.getXCoordinate());
    double xldis = abs(leftx - ball.getXCoordinate());
    double max = ball.getRadius();
    double max_sd = max * Config::sin45;

    if ( (xrdis < max) || (xldis < max) ) {
        if (ball.getYCoordinate() < topy && ball.getYCoordinate() > boty) {
            this->xCollision(ball);
        } else if (pointDistance(leftx, topy , ball.getXCoordinate(), ball.getYCoordinate()) < max) {
            if (xrdis < max_sd || xldis < max_sd) {
                this->yCollision(ball);
            } else {
                this->xCollision(ball);
            }
        } else if (pointDistance(rightx, topy , ball.getXCoordinate(), ball.getYCoordinate()) < max) {
            if (xrdis < max_sd || xldis < max_sd) {
                this->yCollision(ball);
            } else {
                this->xCollision(ball);
            }        
        } else if (pointDistance(leftx, boty , ball.getXCoordinate(), ball.getYCoordinate()) < max) {
            if (xrdis < max_sd || xldis < max_sd) {
                this->yCollision(ball);
            } else {
                this->xCollision(ball);
            }        
        } else if (pointDistance(rightx, boty , ball.getXCoordinate(), ball.getYCoordinate()) < max) {
            if (xrdis < max_sd || xldis < max_sd) {
                this->yCollision(ball);
            } else {
                this->xCollision(ball);
            }        
        }
    }

}

void PaddleModel::yCollision(BallModel& ball) {
    double topy = this->y + length/2;
    double boty = this->y - length/2;

    ball.collideY();
    ball.setYVelocity(ball.getYVelocity() + this->yV);

    if(abs(topy - ball.getYCoordinate()) >  abs(boty - ball.getYCoordinate())) {
        ball.setYCoordinate(boty - ball.getRadius());
    } else {
        ball.setYCoordinate(topy + ball.getRadius());
    }
}

void PaddleModel::xCollision(BallModel& ball) {
    double leftx = this->x - width/2;
    double rightx = this->x + width/2;

    ball.collideX();
    ball.setYVelocity(ball.getYVelocity() + this->yV/3);

    if(abs(leftx - ball.getXCoordinate()) >  abs(rightx - ball.getXCoordinate())) {
        ball.setXCoordinate(rightx + ball.getRadius());
    } else {
        ball.setXCoordinate(leftx - ball.getRadius());
    }
}


}  // pong namespace
