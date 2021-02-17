#include "PolygonalChain.h"

PolygonalChain::PolygonalChain() :
  countPoints(0), points(nullptr){}

PolygonalChain::PolygonalChain(int new_countsPoints, Point *new_points) :
  countPoints(new_countsPoints) {
  points = new Point[countPoints];
  for (int i = 0; i < countPoints; i++) {
    points[i] = Point(new_points[i].getX(), new_points[i].getY());
  }
}

PolygonalChain::~PolygonalChain() {
  delete points;
}

int PolygonalChain::getN() const {
  return countPoints;
}

Point PolygonalChain::getPoint(int index) const {
  return points[index];
}

double PolygonalChain::perimeter() const {
  double res = 0;
  for (int i = 0; i < countPoints - 1; i++) {
    res += points[i].getDistance(points[i + 1]);
  }
  return res;
}
