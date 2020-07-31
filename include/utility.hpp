# pragma once

#include <cmath>

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

double pointDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow((x1 - x2), 2) + std::pow((y1 - y2), 2));
}


}  // pong namespace
