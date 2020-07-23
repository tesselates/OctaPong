#pragma once


namespace pong {

class PaddleModel {

public:
    PaddleModel();
    PaddleModel(double xCoordinate, double yCoordinate);

    void set_up(bool is_up) { this->is_up = is_up; };
    void set_down(bool is_down) { this->is_down = is_down; };

    /**
     * moves the player based on the current velocity
     */
    void move(); 
    void velocity_update(); 

private:
    double xCoordinate;
    double yCoordinate;

    double yVelocity = 0;
    double xVelocity = 0;
    
    double yAcceleration = 0;
    double xAcceleration = 0;
    double acceleration_multiplier = 0.01;
    double velocity_threshold = 0.10;

    bool is_up = false;
    bool is_down = false;

    friend class PaddleModel;
};


}  // pong namespace
