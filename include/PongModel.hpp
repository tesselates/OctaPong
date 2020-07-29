#pragma once

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include "PaddleModel.hpp"
#include "BallModel.hpp"
#include "LifeLine.hpp"
#include <vector>


namespace pong {

class PongModelListener {
public:
    virtual void fireChangeEvent() = 0;
};

class LifeChangeListener {
public:
    virtual void lifeChanged(int life) = 0;
    virtual void gameOver() = 0;
};

typedef std::vector<PongModelListener*> PongModelListeners;
typedef std::vector<LifeChangeListener*> LifeChangeListeners;


class PongModel {
public:
    PongModel(); 

    void setUpTwoPlayerGame();


    void setUpPaddle (size_t paddleNumber, bool is_up) { paddles[paddleNumber].set_up(is_up); }
    void setDownPaddle (size_t paddleNumber, bool is_down) { paddles[paddleNumber].set_down(is_down); }
    const PaddleModel& getPaddle(size_t paddle) const { return paddles[paddle]; }
    const BallModel& getBall(size_t ball) const { return balls[ball]; }
    void progressGame(double frequency); 
    void addListener(PongModelListener* listener) { listeners.push_back(listener); };



private:
    PongModelListeners listeners;
    LifeChangeListeners lifeListeners;

    struct Player {
        int life = 10;
        void reduceLife() {
            life--;
        };
    };
    
    void boundryCollision(BallModel& ball);
    void reset();

    size_t p_n;
    size_t b_n;

    double xSize;
    double ySize;

    PaddleModel paddles[8];
    BallModel balls[8];
    LifeLine lifelines[8];
    Player players[8];
};


}  // pong namespace
