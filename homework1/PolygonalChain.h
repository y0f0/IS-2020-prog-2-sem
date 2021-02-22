#ifndef HOMEWORK1_POLYGONAL_CHAIN_H
#define HOMEWORK1_POLYGONAL_CHAIN_H

#include "Point.h"
#include <stdexcept>

class PolygonalChain {
protected:
  int n_;
  Point *points_;
public:
  PolygonalChain();
  PolygonalChain(int n, Point *points);

  PolygonalChain(const PolygonalChain& other);
  PolygonalChain& operator=(const PolygonalChain& other);
  virtual ~PolygonalChain();

  int getN() const;
  Point getPoint(int index) const;
  virtual double perimeter() const;
};

#endif //HOMEWORK1_POLYGONAL_CHAIN_H
