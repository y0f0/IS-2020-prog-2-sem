#include "PolygonalChain.h"

PolygonalChain::PolygonalChain() :
  n(0), points(nullptr){}

PolygonalChain::PolygonalChain(int new_countsPoints, Point *new_points) :
  n(new_countsPoints) {
  points = new Point[n];
  for (int i = 0; i < n; i++) {
    points[i] = Point(new_points[i].getX(), new_points[i].getY());
  }
}

int PolygonalChain::getN() const {
  return n;
}

Point PolygonalChain::getPoint(int index) const {
  if (index >= 0 && index < n) {
    return points[index];
  }
  throw std::invalid_argument("Wrong index!");
}

double PolygonalChain::perimeter() const {
  double res = 0;
  for (int i = 0; i < n - 1; i++) {
    res += points[i].getDistance(points[i + 1]);
  }
  return res;
}
