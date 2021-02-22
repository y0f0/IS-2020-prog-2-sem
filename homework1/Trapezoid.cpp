#include "Trapezoid.h"

Trapezoid::Trapezoid()
  : Polygon(),
    basis1(0),
    basis2(0) {}

Trapezoid::Trapezoid(int n, Point *points)
  : Polygon(n, points) {
  if (n_ != 4) {
    throw std::invalid_argument("The trapezoid has 4 peaks!");
  }
  auto a = Vector(points_[0], points_[1]);
  auto b = Vector(points_[1], points_[2]);
  auto c = Vector(points_[2], points_[3]);
  auto d = Vector(points_[3], points_[0]);
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
Trapezoid::Trapezoid(const Trapezoid &other)
  : Polygon(other) {
  basis1 = other.basis1;
  basis2 = other.basis2;
}

Trapezoid &Trapezoid::operator=(const Trapezoid &other) {
  if (&other == this) {
    return *this;
  }
  n_ = other.n_;
  points_ = new Point[n_];
  for (int i = 0; i < n_; i++) {
    points_[i] = Point(other.points_[i].getX(), other.points_[i].getY());
  }
  basis1 = other.basis1;
  basis2 = other.basis2;
  return *this;
}

Trapezoid::~Trapezoid() { }

double Trapezoid::height() const {
  double s = this->area();
  return  2 * s / (basis2 + basis1);
}
