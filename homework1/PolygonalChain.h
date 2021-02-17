#ifndef HOMEWORK1_POLYGONAL_CHAIN_H
#define HOMEWORK1_POLYGONAL_CHAIN_H

#include "Point.h"

class PolygonalChain {
protected:
  int countPoints;
  Point *points;
public:
  PolygonalChain();
  PolygonalChain(int new_countsPoints, Point *new_points);
  PolygonalChain(const PolygonalChain& pc) = default;
  PolygonalChain& operator=(const PolygonalChain& pc) = default;
  ~PolygonalChain();

  [[nodiscard]] int getN() const;
  [[nodiscard]] Point getPoint(int index) const;
  [[nodiscard]] virtual double perimeter() const;
};

#endif //HOMEWORK1_POLYGONAL_CHAIN_H
