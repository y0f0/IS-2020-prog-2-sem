#include <cmath>
#include "RegularPolygon.h"

RegularPolygon::RegularPolygon()
  : Polygon() {}

RegularPolygon::RegularPolygon(int n, Point *points)
  : Polygon(n, points) {
  if (n_ < 3) {
    throw std::invalid_argument("Error : Invalid number of vertices for a regular polygon.");
  }
  double dist = points_[0].getDistance(points_[1]);
  for (int i = 1; i + 1 < n_; i++) {
    if (dist != points_[i].getDistance(points_[i + 1])) {
      throw std::invalid_argument("Error : Invalid side length for regular polygon.");
    }
  }
  if (dist != points_[n_ - 1].getDistance(points_[0])) {
    throw std::invalid_argument("Error : Invalid side length for regular polygon.");
  }
  auto v1 = Vector(points_[0], points_[1]);
  auto v2 = Vector(points_[1], points_[2]);
  auto angle = v1.getAngle(v2);
  for (int i = 2; i + 1 < n_; i++) {
    v1 = v2;
    v2 = Vector(points_[i], points_[i + 1]);
    if (angle != v1.getAngle(v2)) {
      throw std::invalid_argument("Error : Incorrect angle between two vertices of a regular polygon.");
    }
  }
  v1 = v2;
  v2 = Vector(points_[n_ - 1], points_[0]);
  if (angle != v1.getAngle(v2)) {
    throw std::invalid_argument("Error : Incorrect angle between two vertices of a regular polygon.");
  }
}
RegularPolygon::RegularPolygon(const RegularPolygon &other)
  : Polygon(other) {}

RegularPolygon::~RegularPolygon() { }

double RegularPolygon::area() const {
  double a = points_[0].getDistance(points_[1]);
  return (n_ * a * a) / (4 * tan(M_PI / n_));
}

double RegularPolygon::perimeter() const {
  double a = points_[0].getDistance(points_[1]);
  return a * n_;
}