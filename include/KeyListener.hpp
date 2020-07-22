#pragma once


#include <QKeyEvent>


class KeyListener {
    virtual void pressEvent(QKeyEvent* event) = 0;
    virtual void releaseEvent(QKeyEvent* event) = 0;
}