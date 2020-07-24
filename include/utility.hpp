# pragma once


namespace pong {

struct CenterCoordinates {
    double x;
    double y;

    CenterCoordinates(double x, double y, double r) {
        this->x = x + r;
        this->y = y + r;
    }

    CenterCoordinates(double x, double y, double xSize, double ySize) {
        this->x = x + xSize/2;
        this->y = y + ySize/2;
    }
};


struct Coordinates {
    double x;
    double y;

    Coordinates(double x, double y, double r) {
        this->x = x - r;
        this->y = y - r;
    }

    Coordinates(double x, double y, double xSize, double ySize) {
        this->x = x - xSize/2;
        this->y = y - ySize/2;
    }
};



}  // pong namespace