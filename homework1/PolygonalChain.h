#ifndef HOMEWORK1_POLYGONAL_CHAIN_H
#define HOMEWORK1_POLYGONAL_CHAIN_H

#include "Point.h"
#include <stdexcept>

class PolygonalChain {
protected:
  int n;
  Point *points;
public:
  PolygonalChain();
  PolygonalChain(int new_countsPoints, Point *new_points);
  PolygonalChain(const PolygonalChain& pc) = default;
  PolygonalChain& operator=(const PolygonalChain& pc) = default;
  ~PolygonalChain() = default;

  int getN() const;
  Point getPoint(int index) const;
  virtual double perimeter() const;
};

#endif //HOMEWORK1_POLYGONAL_CHAIN_H
