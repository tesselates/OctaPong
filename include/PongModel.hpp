#pragma once

#include "BallModel.hpp"
#include "LifeLine.hpp"
#include "PaddleModel.hpp"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <vector>


namespace pong {


/**
 *  Interface for classes that listen to changes in positions of the game model
 */ 
class PongModelListener {
public:
    virtual void fireChangeEvent() = 0;
};


/**
 *  Interface for classes that listen to changes in player life
 */ 
class LifeChangeListener {
public:
    virtual void lifeChanged(int player) = 0;
    virtual void gameOver(int player) = 0;
};


/**
 * Struct that holds player lives
 */ 
struct Player {
    int life;
    void reduceLife() { life--; };
};


typedef std::vector<PongModelListener*> PongModelListeners;
typedef std::vector<LifeChangeListener*> LifeChangeListeners;


/**
 * 
 */ 
class PongModel {
public:
    PongModel(); 

    /**
     *  Access methods
     */ 
    void setUpPaddle (size_t paddleNumber, bool is_up) { paddles[paddleNumber].set_up(is_up); }
    void setDownPaddle (size_t paddleNumber, bool is_down) { paddles[paddleNumber].set_down(is_down); }

    const PaddleModel& getPaddle(size_t paddle) const { return paddles[paddle]; }
    const BallModel& getBall(size_t ball) const { return balls[ball]; }
    const Player& getPlayer(size_t player) const { return players[player]; }

    void addListener(PongModelListener* listener) { listeners.push_back(listener); };
    void addLifeChangeListener(LifeChangeListener* listener) { lifeListeners.push_back(listener); };

    double width() const { return xSize; };
    double height() const { return ySize; };
    size_t playerNumber() const { return p_n; };
    size_t ballNumber() const { return b_n; }


    /**
     *  Class logic
     */

    /**
     *  Set up all variables for a two player game
     */ 
    void setUpTwoPlayerGame();

    /**
     *  Progress the game by moving sub models 
     * 
     *  @param frequency            the frequency indicates with which frequency this method is called, the greater the frequency the smaller the game progression
     */ 
    void progressGame(double frequency); 

    /**
     *  Reset all variables for a two player game
     */ 
    void reset();

    /**
     *  Move paddles and balls to the start position
     */ 
    void startPositions();


private:
    PongModelListeners listeners;  // list of listeners of the game model
    LifeChangeListeners lifeListeners;  // list of listeners of changes in player lives

    size_t p_n;  // number of players
    size_t b_n;  // number of balls

    double xSize;  // x size
    double ySize;  // y size

    PaddleModel paddles[8];  // all the paddle models
    BallModel balls[8];  // all the ball models
    LifeLine lifelines[8];  // all the life lines
    Player players[8];  // all the players

    /**
     *  Tests and performs an elasitc collision with a ball and the boundries of the game board
     * 
     * @param ball      the ball that is tested
     */ 
    void boundryCollision(BallModel& ball);
};


}  // pong namespace
