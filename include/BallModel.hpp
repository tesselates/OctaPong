#pragma once


namespace pong {

class BallModel {

public:
    BallModel(double r);
    BallModel() = default;

    double getRadius() const { return r; };
    double getXCoordinate() const { return x; };
    double getYCoordinate() const { return y; };
    double getYVelocity() const { return yV; };
    double getxVelocity() const { return xV; };

    void collideX() { this->xV *= -1; };
    void collideY() { this->yV *= -1; };

    void setXVelocity (double xV) { this->xV = xV; };
    void setYVelocity (double yV) { this->yV = yV; };
    void setXCoordinate(double x) { this->x = x; };
    void setYCoordinate(double y) { this->y = y; };

    void move(double frequency); 

private:
    double r;

    double x;
    double y;

    double xV = 0;
    double yV = 0;
};


}  // pong namespace
