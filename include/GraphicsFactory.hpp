#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include "config.hpp"
#include "PongModel.hpp"
#include "PongView.hpp"

namespace pong {

class GraphicsFactory 
{
public:
	GraphicsFactory(PongView* pongView, PongModel* pongModel);
    QGraphicsRectItem* createPaddle(size_t playerNumber);
    QGraphicsEllipseItem* createBall(size_t ballNumber);

private:
    PongView* pongView;
    PongModel* pongModel;

    void updateProportion() {};
    double xProp = 1;
    double yProp = 1;
};


}  // pong namespace