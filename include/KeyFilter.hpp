#pragma once

#include "KeyListener.hpp"


namespace pong {


/**
 *  Class to handle QT keyboard inputs and fileters them for the model
 *  This class decouples the QT library from the game model
 */
class KeyFilter : public KeyListener {

public:
    /**
     * @param up                    key to indicate the "up" movement
     * @param down                  key to indicate the "down" movement
     * @param upKeyResponse         function that passes on when the up key is pressed and when it is released
     * @param downKeyResponse       function that passes on when the down key is pressed and when it is released
     */ 
    KeyFilter(Qt::Key up, Qt::Key down, const std::function<void(bool)>& upKeyResponse,  const std::function<void(bool)>& downKeyResponse);
    KeyFilter() = default;


    /** 
     * Method that checks if incoming key press events match the up or down key
     * 
     * @param event         passes on which key is pressed
     */ 
    void pressEvent(QKeyEvent* event) override;

    /** 
     * Method that checks if incoming key release events match the up or down key
     * 
     * @param event         passes on which key is released
     */ 
    void releaseEvent(QKeyEvent* event) override;


private:
    Qt::Key up;
    Qt::Key down;
    
    std::function<void(bool)> upKeyResponse;  
    std::function<void(bool)> downKeyResponse;
};


}  // pong namespace
