#ifndef HOMEWORK1_REGULAR_POLYGON_H
#define HOMEWORK1_REGULAR_POLYGON_H

#include "Polygon.h"
//todo area and perimeter
class RegularPolygon : public Polygon {
public:
  RegularPolygon();
  RegularPolygon(int n, Point *points);

  RegularPolygon(const RegularPolygon& other);
  using PolygonalChain::operator=;
  ~RegularPolygon();
};


#endif //HOMEWORK1_REGULAR_POLYGON_H
