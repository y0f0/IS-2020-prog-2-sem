#include "Polygon.h"
#include <functional>
#include <iostream>

Polygon::Polygon()
  : ClosedPolygonalChain() {}

Polygon::Polygon(int new_n, Point *new_points)
  : ClosedPolygonalChain(new_n, new_points) { //Проверка на выпуклость

  enum sign{
    NEGATIVE,     // = 0
    ZERO,         // = 1
    POSITIVE      // = 2
  };

  int *count = new int[3] {0, 0, 0};

  auto changeCount = [] (const double &product, int *&count) {
    if (product < 0) {
      count[sign::NEGATIVE]++;
    } else if (product == 0) {
      count[sign::ZERO]++;
    } else if (product > 0) {
      count[sign::POSITIVE]++;
    }
  };

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      auto v1 = Vector(points[n - 1], points[0]);
      auto v2 = Vector(points[0], points[1]);
      changeCount(v1.getCrossProduct(v2), count);
    }
    else if (i == n - 1) {
      auto v1 = Vector(points[n - 2], points[n - 1]);
      auto v2 = Vector(points[n - 1], points[0]);
      changeCount(v1.getCrossProduct(v2), count);
    }
    else {
      auto v1 = Vector(points[i - 1], points[i]);
      auto v2 = Vector(points[i], points[i + 1]);
      changeCount(v1.getCrossProduct(v2), count);
    }
  }

  if ((count[0] && count[1]) || (count[1] && count[2]) || (count[0] && count[2])) {
    throw std::invalid_argument("Error : Non-convex polygon.");
  }
}

double Polygon::area() const {
  double res = 0;
  for (int i = 0; i + 1 < n; i++) {
    res += points[i].getX() * points[i + 1].getY();
  }
  for (int i = 0; i + 1 < n; i++) {
    res -= points[i + 1].getX() * points[i].getY();
  }
  res -= points[0].getX() * points[n - 1].getY();
  res = std::abs(res) * 0.5;
  return res;
}


