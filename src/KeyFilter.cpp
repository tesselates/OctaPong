#include "KeyFilter.hpp"


namespace pong {


KeyFilter::KeyFilter(Qt::Key up, Qt::Key down, const std::function<void(bool)>& upKeyResponse,  const std::function<void(bool)>& downKeyResponse) : 
    up(up),
    down(down),
    upKeyResponse(upKeyResponse),
    downKeyResponse(downKeyResponse)
{

}

void KeyFilter::pressEvent(QKeyEvent* event) {
    if (event->key() == this->up) {
        this->upKeyResponse(true);
    } else if (event->key() == this->down) {
        this->downKeyResponse(true);
    } 
};

void KeyFilter::releaseEvent(QKeyEvent* event) {
    if (event->key() == this->up) {
        this->upKeyResponse(false);
    } else if (event->key() == this->down) {
        this->downKeyResponse(false);
    } 
};


}  // pong namespace
