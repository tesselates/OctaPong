#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include "config.hpp"
#include "PongModel.hpp"
#include "PongView.hpp"

namespace pong {

class GraphicsManager : public PongModelListener
{
public:
    QGraphicsRectItem* paddleGraphics[8];
    QGraphicsRectItem* ballGraphics[8];

	GraphicsManager(PongView* pongView, PongModel* pongModel);
    QGraphicsRectItem* createPaddle(size_t playerNumber);
    QGraphicsEllipseItem* createBall(size_t ballNumber);

private:
    PongView* pongView;
    PongModel* pongModel;

    void updateProportion();
    void fireChangeEvent() override;
    double xProp = 1;
    double yProp = 1;
};


}  // pong namespace
