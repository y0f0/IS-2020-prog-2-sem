#include "PolygonalChain.h"

PolygonalChain::PolygonalChain() :
  countPoints(0), points(nullptr){}

PolygonalChain::PolygonalChain(int new_countsPoints, Point *new_points) :
  countPoints(new_countsPoints), points(new_points) {}

PolygonalChain::PolygonalChain(const PolygonalChain &pc) :
  countPoints(pc.countPoints), points(pc.points) {}

PolygonalChain &PolygonalChain::operator=(const PolygonalChain &pc) {
  if (this == &pc) {
    return *this;
  }
  countPoints = pc.countPoints;
  points = pc.points;
  return *this;
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
