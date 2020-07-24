#include "GraphicsFactory.hpp"
#include <QPainter>

namespace pong {

GraphicsFactory::GraphicsFactory(PongView* pongView, PongModel* pongModel) : pongView(pongView), pongModel(pongModel) {}

QGraphicsRectItem* GraphicsFactory::createPaddle(size_t playerN) {

    updateProportion();

    QGraphicsRectItem* player = new QGraphicsRectItem();
    const auto& paddle = pongModel->getPaddle(playerN);
    player->setRect((paddle.getXCoordinate() - paddle.getWidth()/2) * xProp, 
                         (paddle.getYCoordinate() * yProp - paddle.getLength()/2) * yProp, 
                         paddle.getWidth() * xProp, paddle.getLength() * yProp);

    player->setBrush(QBrush(Qt::red));

    return player;
}

QGraphicsEllipseItem* GraphicsFactory::createBall(size_t ballN) {

    updateProportion();

    QGraphicsEllipseItem* ball = new QGraphicsEllipseItem();
    const auto& ballModel = pongModel->getBall(ballN);
    ball->setRect((ballModel.getXCoordinate() - ballModel.getRadius()) * xProp, 
                         (ballModel.getYCoordinate() - ballModel.getRadius()) * yProp, 
                         ballModel.getRadius() * xProp, ballModel.getRadius() * yProp);

    ball->setBrush(QBrush(Qt::red));

    return ball;
}

}  // pong namespace