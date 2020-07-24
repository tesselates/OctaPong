#pragma once


#include <QKeyEvent>




class KeyListener {
public:
    virtual void pressEvent(QKeyEvent* event) = 0;
    virtual void releaseEvent(QKeyEvent* event) = 0;
};

typedef std::vector<KeyListener*> KeyListeners;