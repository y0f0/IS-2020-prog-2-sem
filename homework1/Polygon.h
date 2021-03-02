#ifndef HOMEWORK1_POLYGON_H
#define HOMEWORK1_POLYGON_H

#include "ClosedPolygonalChain.h"

class Polygon : public ClosedPolygonalChain {
public:
  Polygon();
  Polygon(int n, Point *points);

  Polygon(const Polygon& other);
  using PolygonalChain::operator=;
  ~Polygon();

  virtual double area() const;

  struct Vector {
    double x;
    double y;
    Vector(const Point& a, const Point& b)
        : x(b.getX() - a.getX()),
          y(b.getY() - a.getY()) {}
    double getCrossProduct(const Vector& other) const {
      return this->x * other.y - this->y * other.x;
    }
    double getScalar(const Vector& other) const {
      return this->x * other.x + this->y * other.y;
    }
    double getLength() const {
      return sqrt(x * x + y * y);
    }
    double getAngle(const Vector& other) const {
      return acos(this->getScalar(other) /
                      (this->getLength() * other.getLength()));
    }
  };
};


#endif //HOMEWORK1_POLYGON_H
