#include "Point.h"

Point::Point()
    : x_(0),
      y_(0) {}

Point::Point(double x, double y)
    : x_(x),
      y_(y) {}

Point::Point(const Point &other)
    : x_(other.getX()),
      y_(other.getY()){}

Point &Point::operator=(const Point &other) {
  if (this == &other) {
    return *this;
  }
  x_ = other.getX();
  y_ = other.getY();
  return *this;
}

double Point::getX() const {
  return x_;
}

double Point::getY() const {
  return y_;
}

double Point::getDistance(const Point &other) const {
  return sqrt((x_ - other.getX()) * (x_ - other.getX()) +
                  (y_ - other.getY()) * (y_ - other.getY()));
}
