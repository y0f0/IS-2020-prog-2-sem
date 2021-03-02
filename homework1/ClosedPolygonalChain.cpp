#include "ClosedPolygonalChain.h"

ClosedPolygonalChain::ClosedPolygonalChain()
  : PolygonalChain() {}

ClosedPolygonalChain::ClosedPolygonalChain(int n, Point *points)
  : PolygonalChain(n, points) {}

ClosedPolygonalChain::ClosedPolygonalChain(const ClosedPolygonalChain &other)
  : PolygonalChain(other) {}

//todo inherit =

ClosedPolygonalChain::~ClosedPolygonalChain() { }

//todo perimeter from base
double ClosedPolygonalChain::perimeter() const {
  double res = 0;
  for (int i = 0; i < n_ - 1; i++) {
    res += points_[i].getDistance(points_[i + 1]);
  }
  res += points_[0].getDistance(points_[n_ - 1]);
  return res;
}
