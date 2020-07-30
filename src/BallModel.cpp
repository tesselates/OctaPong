#include "BallModel.hpp"


namespace pong {



BallModel::BallModel(double r) : r (r) {}

void BallModel::move(double frequency) {
    this->y += yV/frequency;
    this->x += xV/frequency;
}

}  // pong namespace
