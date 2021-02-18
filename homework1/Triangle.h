#ifndef HOMEWORK1_TRIANGLE_H
#define HOMEWORK1_TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon {
public:
  Triangle()
    : Polygon() {}

  Triangle(const Triangle& tr) = default;
  Triangle& operator=(const Triangle& tr) = default;

  Triangle(int new_n, Point *points)
    : Polygon(new_n, points) {
    if (n != 3) {
      throw std::invalid_argument("Error: Number of vertices is incorrect");
    }
  }

  bool hasRightAngle() const {
    auto v1 = Vector(points[0], points[1]);
    auto v2 = Vector(points[1], points[2]);
    auto v3 = Vector(points[2], points[0]);
    return v1.getScalar(v2) == 0 || v2.getScalar(v3) == 0 || v1.getScalar(v3) == 0;
  }

};


#endif //HOMEWORK1_TRIANGLE_H
