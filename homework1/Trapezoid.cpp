#include "Trapezoid.h"

Trapezoid::Trapezoid()
  : Polygon(), basis1(0), basis2(0) {}

Trapezoid::Trapezoid(int new_n, Point *new_points)
  : Polygon(new_n, new_points) {
  if (n != 4) {
    throw std::invalid_argument("The trapezoid has 4 peaks!");
  }
  auto a = Vector(points[0], points[1]);
  auto b = Vector(points[1], points[2]);
  auto c = Vector(points[2], points[3]);
  auto d = Vector(points[3], points[0]);
  if (a.getCrossProduct(c) == 0 && b.getCrossProduct(d) != 0) {
    basis1 = a.getLength();
    basis2 = c.getLength();
  } else if (a.getCrossProduct(c) != 0 && b.getCrossProduct(d) == 0) {
    basis1 = b.getLength();
    basis2 = d.getLength();
  } else {
    throw std::invalid_argument("This is not a trapezoid!");
  }
}

double Trapezoid::height() const {
  double s = this->area();
  return  2 * s / (basis2 + basis1);
}
