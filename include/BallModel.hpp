#pragma once


namespace pong {

class BallModel {

public:
    BallModel(double r);
    BallModel() = default;

    double getRadius() const { return r; };
    double getXCoordinate() const { return x; };
    double getYCoordinate() const { return y; };

    void move(double frequency); 
    void collideX() { this->xV *= -1; };
    void collideY() { this->yV *= -1; };
    
private:
    double r;

    double x;
    double y;

    double yV = 0;
    double xV = 0;

    friend class PongModel;
};


}  // pong namespace
