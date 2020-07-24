#pragma once

#include "KeyListener.hpp"

namespace pong {


/**
 *  Class handless QT keyboard inputs and fileters them for the model
 *  This class serves interfaces the model and QT-gui library
 */

class KeyFilter : public KeyListener {

public:
    /**
     * Constructor
     */
    KeyFilter(Qt::Key up, Qt::Key down, const std::function<void(bool)>& upKeyResponse,  const std::function<void(bool)>& downKeyResponse);

    /** 
     * @param event         the key press event
     */ 
    void pressEvent(QKeyEvent* event) override;
    void releaseEvent(QKeyEvent* event) override;
private:
    Qt::Key up;
    Qt::Key down;
    std::function<void(bool)> upKeyResponse;
    std::function<void(bool)> downKeyResponse;
};


}  // pong namespace
