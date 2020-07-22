#pragma once

#include "KeyListener.hpp"

namespace pong {


/**
 *  Class handless QT keyboard inputs and fileters them for the model
 *  This class serves interfaces the model and QT-gui library
 */

class PaddleController : public KeyListener {

public:
    PadelModel padelModel;
    /**
     * Constructor
     */
    PaddleController(Qt::Key up, Qt::Key down, PadelModel padelmodel);
    PaddleController(PadelModel padelmodel);

    void setPadelModel(PadelModel padelmodel) { this->padelModel = padelModel; };

    /** 
     * @param event         the key press event
     */ 
    void pressEvent(QKeyEvent* event) override;
    void releaseEvent(QKeyEvent* event) override;
private:
    Qt::Key up;
    Qt::Key down;

};


}  // pong namespace
