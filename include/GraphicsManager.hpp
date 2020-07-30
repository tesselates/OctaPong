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
    QGraphicsEllipseItem* ballGraphics[8];

	GraphicsManager(PongView* pongView, PongModel* pongModel);
	GraphicsManager() = default;
    QGraphicsRectItem* createPaddle(size_t playerNumber);
    QGraphicsEllipseItem* createBall(size_t ballNumber);

    void fireChangeEvent() override;
private:
    PongView* pongView;
    PongModel* pongModel;

    void updateProportion();
    double xProp = 1;
    double yProp = 1;
};


}  // pong namespace
