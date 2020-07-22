#include "PaddleController.hpp"


namespace pong {


PaddleController::PaddleController(Qt::Key up, Qt::Key down, PadelModel padelmodel) : 
    up(up),
    down(down),
    padelModel(padelModel)
{

}

PaddleController::PaddleController(PadelModel padelmodel) : PaddleController(Qt::Key_Up, Qt::Key_Down, padelmodel) {};

void PaddleController::pressEvent(QKeyEvent* event) {
    if (event->key() == this->up) {
        this->padelModel.set_up(true);
    } else if (event->key() == this->down) {
        this->padelModel.set_down(true);
    } 
};

void PaddleController::releaseEvent(QKeyEvent* event) {
    if (event->key() == this->up) {
        this->padelModel.set_up(false);
    } else if (event->key() == this->down) {
        this->padelModel.set_down(false);
    } 
};


}  // pong namespace
