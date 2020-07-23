#pragma once

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include "PaddleModel.hpp"

namespace pong {

class PongModel {

public:
    PongModel() : xSize(1000), ySize(1000) {
        
    }



private:
    double xSize;
    double ySize;

    PaddleModel paddles[8];

    template<void (*F), class ... Types> 
    void manipulatePaddle (size_t paddleNumber, Types ... args) {
        paddles[paddleNumber].F(&args...);
    }
};


}  // pong namespace
