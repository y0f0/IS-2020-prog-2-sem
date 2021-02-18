#ifndef HOMEWORK1_CLOSED_POLYGONAL_CHAIN_H
#define HOMEWORK1_CLOSED_POLYGONAL_CHAIN_H

#include "PolygonalChain.h"

class ClosedPolygonalChain : public PolygonalChain {
  using PolygonalChain::PolygonalChain;
public:
  double perimeter() const override {
    double res = 0;
    for (int i = 0; i < n - 1; i++) {
      res += points[i].getDistance(points[i + 1]);
    }
    res += points[0].getDistance(points[n - 1]);
    return res;
  }
};



#endif //HOMEWORK1_CLOSED_POLYGONAL_CHAIN_H
