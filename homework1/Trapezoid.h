#ifndef HOMEWORK1_TRAPEZOID_H
#define HOMEWORK1_TRAPEZOID_H

#include "Polygon.h"

class Trapezoid : public Polygon {
private:
  double basis1;
  double basis2;
public:
  Trapezoid();
  Trapezoid(int new_n, Point *new_points);
  Trapezoid(const Trapezoid &tr) = default;
  Trapezoid& operator=(const Trapezoid& tr) = default;
  double height() const;
};


#endif //HOMEWORK1_TRAPEZOID_H
