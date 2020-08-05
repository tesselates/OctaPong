#include "PongModel.hpp"
#include "config.hpp"

namespace pong {


PongModel::PongModel() : xSize(Config::view_width), ySize(Config::view_height)  {}

void PongModel::setUpTwoPlayerGame() {
    p_n = 2;
    b_n = 1;

    paddles[0] = PaddleModel(Config::paddle_thinckness, Config::paddle_length);
    paddles[1] = PaddleModel(Config::paddle_thinckness, Config::paddle_length);

    balls[0] = BallModel(10);
    lifelines[0] = LifeLine(balls[0].getRadius() + 1, 1);
    lifelines[1] = LifeLine(this->xSize - balls[0].getRadius() - 1, -1);
    this->reset();
}

void PongModel::reset() {
    paddles[0].setXCoordinate(Config::distance_buffer);
    paddles[0].setYCoordinate(this->ySize/2);
    paddles[0].setYVelocity(0);

    paddles[1].setXCoordinate(this->xSize - paddles[0].getWidth() - Config::distance_buffer);
    paddles[1].setYCoordinate(this->ySize/2);
    paddles[1].setYVelocity(0);

    balls[0].setXCoordinate(this->xSize/2);
    balls[0].setYCoordinate(this->ySize/2);

    balls[0].setXVelocity(40 * (-1 + (2 * (rand() % 2))));
    balls[0].setYVelocity(-0.1);

    for (auto& i : listeners) {
        i->fireChangeEvent();
    }
}


void PongModel::progressGame(double frequency) {
    
    for (size_t i = 0; i < p_n; i++) {
        paddles[i].move(frequency);
        if (paddles[i].getYCoordinate() - paddles[i].getLength()/2 < 0) {
            paddles[i].setYVelocity(0);
            paddles[i].setYCoordinate(paddles[i].getLength()/2);
        } else if (paddles[i].getYCoordinate() + paddles[i].getLength()/2 > this->ySize) {
            paddles[i].setYVelocity(0);
            paddles[i].setYCoordinate(this->ySize - paddles[i].getLength()/2);
        }
        paddles[i].velocity_update(frequency);
    }

    for (size_t i = 0; i < b_n; i++) {
        balls[i].move(frequency);
        this->boundryCollision(balls[i]);
        for (size_t j = 0; j < p_n; j++) {
            if (lifelines[j].testCrossing(balls[i])) {
                this->reset();
                players[j].reduceLife();
                for (auto& i : lifeListeners) {
                    i->lifeChanged(j);
                }
            } else {
                paddles[j].enactCollision(balls[i]);
            }
        }
    }
    
    for (auto& i : listeners) {
        i->fireChangeEvent();
    }
}


void PongModel::boundryCollision(BallModel& ball) {
    if (ball.getYCoordinate() - ball.getRadius()/2 < 0 || ball.getYCoordinate() + ball.getRadius()/2 > ySize) {
        ball.collideY();
    }

    if (ball.getXCoordinate() - ball.getRadius()/2 < 0 || ball.getXCoordinate() + ball.getRadius()/2 > xSize) {
        ball.collideX();
    }

}

}  // pong namespace
