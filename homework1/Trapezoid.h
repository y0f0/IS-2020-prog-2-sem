#ifndef HOMEWORK1_TRAPEZOID_H
#define HOMEWORK1_TRAPEZOID_H

#include "Polygon.h"

class Trapezoid : public Polygon {
private:
  double basis1;
  double basis2;
public:
  Trapezoid();
  Trapezoid(int n, Point *points);

  Trapezoid(const Trapezoid& other);
  Trapezoid& operator=(const Trapezoid& other);
  ~Trapezoid();

  double height() const;
};


#endif //HOMEWORK1_TRAPEZOID_H
