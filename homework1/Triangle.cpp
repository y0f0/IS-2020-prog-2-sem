#include "Triangle.h"

Triangle::Triangle()
  : Polygon() {}

Triangle::Triangle(int n, Point *points)
  : Polygon(n, points) {
  if (n_ != 3) {
    throw std::invalid_argument("Error: Number of vertices is incorrect");
  }
}

Triangle::Triangle(const Triangle &other)
  : Polygon(other) {}

Triangle::~Triangle() { }

bool Triangle::hasRightAngle() const {
  auto v1 = Vector(points_[0], points_[1]);
  auto v2 = Vector(points_[1], points_[2]);
  auto v3 = Vector(points_[2], points_[0]);
  return v1.getScalar(v2) == 0 || v2.getScalar(v3) == 0 || v1.getScalar(v3) == 0;
}
