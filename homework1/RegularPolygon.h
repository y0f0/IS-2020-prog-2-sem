#ifndef HOMEWORK1_REGULARPOLYGON_H
#define HOMEWORK1_REGULARPOLYGON_H

#include "Polygon.h"

class RegularPolygon : public Polygon {
public:
  RegularPolygon();
  RegularPolygon(int new_n, Point *new_points);
  RegularPolygon(const RegularPolygon& rp) = default;
  RegularPolygon& operator=(const RegularPolygon& rp) = default;
};


#endif //HOMEWORK1_REGULARPOLYGON_H
