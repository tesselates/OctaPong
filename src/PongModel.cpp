#include "PongModel.hpp"
#include "config.hpp"

namespace pong {


PongModel::PongModel() : xSize(1000), ySize(1000)  {}

void PongModel::setUpTwoPlayerGame() {
    p_n = 2;
    b_n = 1;

    paddles[0] = PaddleModel(Config::paddle_thinckness, Config::paddle_length);
    paddles[1] = PaddleModel(Config::paddle_thinckness, Config::paddle_length);

    paddles[0].xCoordinate = Config::distance_buffer;
    paddles[0].yCoordinate = this->ySize - paddles[0].ySize/2;

    paddles[1].xCoordinate = this->xSize - paddles[0].xSize - Config::distance_buffer;
    paddles[1].yCoordinate = this->ySize - paddles[0].ySize/2;

    lifelines[0] = LifeLine(Config::distance_buffer, 0, 1, 1);
    lifelines[1] = LifeLine(this->xSize - Config::distance_buffer, 0, -1, 1);

    balls[0] = BallModel(30);
    balls[0].x = xSize/2;
    balls[0].y = ySize/2;
}

void PongModel::progressGame(double frequency) {
    for (size_t i = 0; i < p_n; i++) {
        paddles[i].move(frequency);
        paddles[i].velocity_update(frequency);
    }

    for (size_t i = 0; i < b_n; i++) {
        balls[i].move(frequency);
        for (size_t j = 0; j < p_n; j++) {
            if (lifelines[j].testCollision(balls[i])) {
                this->reset();
                players[j].reduceLife();
            } else {
                paddles[j].enactCollision(balls[i]);
            }
        }
    }
    for (auto& i : listeners) {
        i->fireChangeEvent();
    }
}


bool PongModel::boundryCollision(BallModel& ball) {
    if (ball.getYCoordinate() - ball.getRadius() < 0 || ball.getYCoordinate() + ball.getRadius() > ySize) {
        ball.collideY();
    }

    if (ball.getXCoordinate() - ball.getRadius() < 0 || ball.getXCoordinate() + ball.getRadius() > xSize) {
        ball.collideX();
    }
}
void PongModel::reset() {

}

}  // pong namespace
