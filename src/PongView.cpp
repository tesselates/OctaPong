#include "PongView.hpp"

#include "config.hpp"

namespace pong {


void PongView::keyPressEvent(QKeyEvent* event) {
    for (auto& i : listeners) {
        i->pressEvent(event);
    }
};

void PongView::keyReleaseEvent(QKeyEvent* event) {
    for (auto& i : listeners) {
        i->releaseEvent(event);
    }
};

}  // pong namespace
