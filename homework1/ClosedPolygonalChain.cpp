#include "ClosedPolygonalChain.h"

ClosedPolygonalChain::ClosedPolygonalChain()
  : PolygonalChain() {}

ClosedPolygonalChain::ClosedPolygonalChain(int n, Point *points)
  : PolygonalChain(n, points) {}

ClosedPolygonalChain::ClosedPolygonalChain(const ClosedPolygonalChain &other)
  : PolygonalChain(other) {}

//fixed inherit =

ClosedPolygonalChain::~ClosedPolygonalChain() { }

//fixed perimeter from base
double ClosedPolygonalChain::perimeter() const {
  double res = PolygonalChain::perimeter();
  res += points_[0].getDistance(points_[n_ - 1]);
  return res;
}
