#include "Point.h"

Point::Point() : X(0), Y(0) {}

Point::Point(int x, int y) : X(x), Y(y) {}

Point::Point(const Point &p) : X(p.getX()), Y(p.getY()){}

int Point::getX() const {
  return X;
}

int Point::getY() const {
  return Y;
}

double Point::getDistance(const Point &p) const {
  return sqrt((X - p.getX()) * (X - p.getX()) +
                  (Y - p.getY()) * (Y - p.getY()));
}

