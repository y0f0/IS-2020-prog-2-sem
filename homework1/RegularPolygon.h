#ifndef HOMEWORK1_REGULAR_POLYGON_H
#define HOMEWORK1_REGULAR_POLYGON_H

#include "Polygon.h"

class RegularPolygon : public Polygon {
public:
  RegularPolygon();
  RegularPolygon(int n, Point *points);

  RegularPolygon(const RegularPolygon& other);
  RegularPolygon& operator=(const RegularPolygon& other);
  ~RegularPolygon();
};


#endif //HOMEWORK1_REGULAR_POLYGON_H
