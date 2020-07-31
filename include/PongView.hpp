#pragma once

#include <QGraphicsView>
#include "KeyFilter.hpp"
#include "KeyFilter.hpp"
#include <vector>


namespace pong {

class PongView : public QGraphicsView {
    Q_OBJECT
public:

    std::vector<QGraphicsRectItem*> paddles;    
    std::vector<QGraphicsEllipseItem*> balls;
    KeyListeners listeners;

    PongView () : QGraphicsView () { };

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

    void addKeyListener(KeyListener* listener) { this->listeners.push_back(listener); };
};


}  // pong namespace
