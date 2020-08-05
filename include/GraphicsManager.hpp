#pragma once

#include "config.hpp"
#include "PongModel.hpp"
#include "PongView.hpp"

#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>


namespace pong {


/**
 *  Class that creates the interface game object with the QT library
 *  and manages their position on the view by listening to changes of the game model
 */ 
class GraphicsManager : public PongModelListener {

public:
    /**
     *  @param pongView             QT object that manages the view of a scene
     *  @param pongModel            the underlying game model for pong
     */ 
	GraphicsManager(PongView* pongView, PongModel* pongModel);
	GraphicsManager() = default;

    /**
     *  Class logic
     */

    /**
     *  Create a rectengular object that is matched with a paddle in the game model
     * 
     *  @param playerNumber     the number of the player for which the paddle is created
     */ 
    QGraphicsRectItem* createPaddle(size_t playerNumber);

    /**
     *  Create a circular object that is matched with a ball in the game model
     * 
     *  @param ballNumber     the number of the ball model in the game model
     */ 
    QGraphicsEllipseItem* createBall(size_t ballNumber);


    /**
     *  Updates the positions of the UI objects by retrieving information from the game model
     */ 
    void fireChangeEvent() override;
    
private:
    QGraphicsRectItem* paddleGraphics[8];  // all the paddles
    QGraphicsEllipseItem* ballGraphics[8];  // all the balls
    PongView* pongView;  // the game view
    PongModel* pongModel;  // the game model

    /**
     *  Updates the proportion modifiers to match that of the current size of the view and the internal coordinate system of the game model
     */ 
    void updateProportion();


    double xProp = 1;  // the x-ax proportion of the model mapped to the view
    double yProp = 1;  // the y-ax proportion of the model mapped to the view
};


}  // pong namespace
