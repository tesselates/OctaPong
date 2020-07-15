#pragma once

#include "PaddleFactory.hpp"

namespace pong {

PaddleFactory::PaddleFactory() {

}

PaddleFactory::QGraphicsRectItem* createPlayer(Alignment alignment) {
    QGraphicsRectItem* player = new QGraphicsRectItem();
    
    if (alignment == Alignment::LEFT) {
        player->setRect(Config::distance_buffer, Config::view_height/2 - Config::paddle_length/2, Config::paddle_thinckness, Config::paddle_length);
    }

    if (alignment == Alignment::RIGHT) {
        player->setRect(Config::view_width - Config::distance_buffer, Config::view_height/2 - Config::paddle_length/2, Config::paddle_thinckness, Config::paddle_length);
    }

    player->setBrush(Qt::white);

    return player;
}

}  // pong namespace