#include "PaddleFactory.hpp"
#include <QPainter>

namespace pong {

PaddleFactory::PaddleFactory() {

}

QGraphicsRectItem* PaddleFactory::createPlayer(Alignment alignment) {

    QGraphicsRectItem* player = new QGraphicsRectItem();
    
    if (alignment == Alignment::LEFT) {
        player->setRect(Config::distance_buffer, Config::view_height/2 - Config::paddle_length/2, Config::paddle_thinckness, Config::paddle_length);
    }

    if (alignment == Alignment::RIGHT) {
        player->setRect(Config::view_width - Config::distance_buffer, Config::view_height/2 - Config::paddle_length/2, Config::paddle_thinckness, Config::paddle_length);
    }

    player->setBrush(QBrush(Qt::red));

    return player;
}

}  // pong namespace