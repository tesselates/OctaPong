#pragma once

#include <cmath>


namespace pong {


double pointDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow((x1 - x2), 2) + std::pow((y1 - y2), 2));
}


}  // pong namespace
