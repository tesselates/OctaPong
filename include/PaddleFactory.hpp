#pragma once

#include <QGraphicsRectItem>
#include "config.hpp"

namespace pong {


enum class Alignment {
    RIGHT,
    LEFT,
    UP,
    DOWN
}



class PaddleFactory 
{
public:
	PaddleFactory();
    QGraphicsRectItem* createPlayer(Alignment alignment);
};


}  // pong namespace