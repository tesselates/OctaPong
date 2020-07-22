#pragma once

#include <QGraphicsView>
#include "PaddleFactory.hpp"


namespace pong {

class PongView : public QGraphicsView {
    Q_OBJECT
public:

    QGraphicsRectItem* players[];

    PongView () : QGraphicsView () {};

    void keyPressEvent(QKeyEvent* event) {
        qDebug()<<"press";
    };
    void keyReleaseEvent(QKeyEvent* event) {
        qDebug()<<"release";
    };

};


}  // pong namespace