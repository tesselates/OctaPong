#pragma once


#include <QKeyEvent>


/**
 *  Interface for classes that listen to the key pressed of a focussed QT object
 */ 
class KeyListener {
public:
    virtual void pressEvent(QKeyEvent* event) = 0;
    virtual void releaseEvent(QKeyEvent* event) = 0;
};

typedef std::vector<KeyListener*> KeyListeners;
