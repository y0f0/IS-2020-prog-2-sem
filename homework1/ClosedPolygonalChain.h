#ifndef HOMEWORK1_CLOSED_POLYGONAL_CHAIN_H
#define HOMEWORK1_CLOSED_POLYGONAL_CHAIN_H

#include "PolygonalChain.h"

class ClosedPolygonalChain : public PolygonalChain {
public:
  ClosedPolygonalChain();
  ClosedPolygonalChain(int n, Point *points);

  ClosedPolygonalChain(const ClosedPolygonalChain &other);
  ClosedPolygonalChain &operator=(const ClosedPolygonalChain &other);
  ~ClosedPolygonalChain();

  double perimeter() const override;
};


#endif //HOMEWORK1_CLOSED_POLYGONAL_CHAIN_H
