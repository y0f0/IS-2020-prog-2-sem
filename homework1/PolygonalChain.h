#ifndef HOMEWORK1_POLYGONALCHAIN_H
#define HOMEWORK1_POLYGONALCHAIN_H

#include "Point.h"

class PolygonalChain {
private:
  int countPoints;
  Point *points;
public:
  PolygonalChain();
  PolygonalChain(int new_countsPoints, Point *new_points);
  PolygonalChain(const PolygonalChain& pc);
  PolygonalChain& operator=(const PolygonalChain& pc);
  ~PolygonalChain();
  int getN() const;
  Point getPoint(int index) const;
  double  perimeter() const;
};

#endif //HOMEWORK1_POLYGONALCHAIN_H
