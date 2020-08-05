#pragma once

#include <QGraphicsView>
#include "KeyFilter.hpp"
#include "KeyFilter.hpp"
#include <vector>


namespace pong {

class PongView : public QGraphicsView {
    Q_OBJECT

public:
    PongView () : QGraphicsView () {};

    /**
     *  Access methods
     */ 
    void addKeyListener(KeyListener* listener) { this->listeners.push_back(listener); };


    /**
     *  Class logic
     */

    /**
     * Registers when a key is pressed
     * 
     * @param event         the key which is pressed
     */
    void keyPressEvent(QKeyEvent* event);

    /**
     * Registers when a key is released
     * 
     * @param event         the key which is released
     */
    void keyReleaseEvent(QKeyEvent* event);

private:
    std::vector<QGraphicsRectItem*> paddles;  // ui paddles
    std::vector<QGraphicsEllipseItem*> balls;  // ui balls
    KeyListeners listeners;  // listeners for the key events
};


}  // pong namespace
