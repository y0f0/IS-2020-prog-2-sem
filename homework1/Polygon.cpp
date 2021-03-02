#include "Polygon.h"

Polygon::Polygon()
  : ClosedPolygonalChain() {}

Polygon::Polygon(int n, Point *points)
  : ClosedPolygonalChain(n, points) { //Проверка на выпуклость

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
      auto v1 = Vector(points_[n - 1], points_[0]);
      auto v2 = Vector(points_[0], points_[1]);
      changeCount(v1.getCrossProduct(v2), count);
    }
    else if (i == n - 1) {
      auto v1 = Vector(points_[n - 2], points_[n - 1]);
      auto v2 = Vector(points_[n - 1], points_[0]);
      changeCount(v1.getCrossProduct(v2), count);
    }
    else {
      auto v1 = Vector(points_[i - 1], points_[i]);
      auto v2 = Vector(points_[i], points_[i + 1]);
      changeCount(v1.getCrossProduct(v2), count);
    }
  }

  if ((count[0] && count[1]) || (count[1] && count[2]) || (count[0] && count[2])) {
    throw std::invalid_argument("Error : Non-convex polygon.");
  }
}
Polygon::Polygon(const Polygon &other)
  : ClosedPolygonalChain(other) {}

Polygon::~Polygon() { }

double Polygon::area() const {
  double res = 0;
  for (int i = 0; i + 1 < n_; i++) {
    res += points_[i].getX() * points_[i + 1].getY();
  }
  for (int i = 0; i + 1 < n_; i++) {
    res -= points_[i + 1].getX() * points_[i].getY();
  }
  res -= points_[0].getX() * points_[n_ - 1].getY();
  res = std::abs(res) * 0.5;
  return res;
}
