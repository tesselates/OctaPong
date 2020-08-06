#include "GraphicsManager.hpp"
#include <QPainter>
#include <QDebug>

namespace pong {

GraphicsManager::GraphicsManager(PongView* pongView, PongModel* pongModel) : pongView(pongView), pongModel(pongModel) {
    updateProportion();
}

QGraphicsRectItem* GraphicsManager::createPaddle(size_t playerN) {
    paddleGraphics[playerN] = new QGraphicsRectItem();
    auto& target = paddleGraphics[playerN];
    const auto& paddle = pongModel->getPaddle(playerN);
    target->setRect((-paddle.getWidth()/2) * xProp, (-paddle.getLength()/2) * yProp, paddle.getWidth() * xProp, paddle.getLength() * yProp);

    target->setBrush(QBrush(Qt::white));
    return target;
}

QGraphicsEllipseItem* GraphicsManager::createBall(size_t ballN) {
    ballGraphics[ballN] = new QGraphicsEllipseItem();
    auto& target = ballGraphics[ballN];
    const auto& ballModel = pongModel->getBall(ballN);
    target->setRect(- ballModel.getRadius()*xProp, - ballModel.getRadius() * yProp, ballModel.getRadius()*2 * xProp, ballModel.getRadius() *2 * yProp);

    target->setBrush(QBrush(Qt::white));

    return target;
}

void GraphicsManager::updateProportion() {
    auto y = this->pongView->sceneRect().height();
    auto x = this->pongView->sceneRect().width();
}

void GraphicsManager::fireChangeEvent() {
  
    
    size_t playerN = this->pongModel->playerNumber();
    for (size_t i = 0; i < playerN; i++) {
        auto& target = paddleGraphics[i];
        const auto& paddle = pongModel->getPaddle(i);
        target->setPos((paddle.getXCoordinate()) * xProp, 
                         (paddle.getYCoordinate()) * yProp);
    }

    size_t ballNumber = this->pongModel->ballNumber();
    for (size_t i = 0; i < ballNumber; i++) {
        auto& target = ballGraphics[i];
        const auto& ballModel = pongModel->getBall(i);
        target->setPos((ballModel.getXCoordinate()) * xProp, 
                         (ballModel.getYCoordinate()) * yProp);
    }
    
}

}  // pong namespacem