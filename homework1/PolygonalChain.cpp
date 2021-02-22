#include "PolygonalChain.h"

PolygonalChain::PolygonalChain()
    : n_(0),
      points_(nullptr) {}

PolygonalChain::PolygonalChain(int n, Point *points)
  : n_(n) {
  points_ = new Point[n_];
  for (int i = 0; i < n_; i++) {
    points_[i] = Point(points[i].getX(), points[i].getY());
  }
}

PolygonalChain::PolygonalChain(const PolygonalChain &other)
  : n_(other.getN()) {
  points_ = new Point[n_];
  for (int i = 0; i < n_; i++) {
    points_[i] = Point(other.points_[i].getX(), other.points_[i].getY());
  }
}

PolygonalChain &PolygonalChain::operator=(const PolygonalChain &other) {
  if (&other == this) {
    return *this;
  }
  delete[] points_;
  points_ = new Point[n_];
  for (int i = 0; i < n_; i++) {
    points_[i] = Point(other.points_[i].getX(), other.points_[i].getY());
  }
  return *this;
}

PolygonalChain ::~PolygonalChain() {
  delete[] points_;
}

int PolygonalChain::getN() const {
  return n_;
}

Point PolygonalChain::getPoint(int index) const {
  if (index >= 0 && index < n_) {
    return points_[index];
  }
  throw std::invalid_argument("Wrong index!");
}

double PolygonalChain::perimeter() const {
  double res = 0;
  for (int i = 0; i < n_ - 1; i++) {
    res += points_[i].getDistance(points_[i + 1]);
  }
  return res;
}
