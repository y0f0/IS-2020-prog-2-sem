#include "RegularPolygon.h"

RegularPolygon::RegularPolygon()
  : Polygon() {}

RegularPolygon::RegularPolygon(int new_n, Point *new_points)
  : Polygon(new_n, new_points) {
  if (n < 3) {
    throw std::invalid_argument("Error : Invalid number of vertices for a regular polygon.");
  }
  double dist = points[0].getDistance(points[1]);
  for (int i = 1; i + 1 < n; i++) {
    if (dist != points[i].getDistance(points[i + 1])) {
      throw std::invalid_argument("Error : Invalid side length for regular polygon.");
    }
  }
  if (dist != points[n - 1].getDistance(points[0])) {
    throw std::invalid_argument("Error : Invalid side length for regular polygon.");
  }
  auto v1 = Vector(points[0], points[1]);
  auto v2 = Vector(points[1], points[2]);
  auto angle = v1.getAngle(v2);
  for (int i = 2; i + 1 < n; i++) {
    v1 = v2;
    v2 = Vector(points[i], points[i + 1]);
    if (angle != v1.getAngle(v2)) {
      throw std::invalid_argument("Error : Incorrect angle between two vertices of a regular polygon.");
    }
  }
  v1 = v2;
  v2 = Vector(points[n - 1], points[0]);
  if (angle != v1.getAngle(v2)) {
    throw std::invalid_argument("Error : Incorrect angle between two vertices of a regular polygon.");
  }
}
