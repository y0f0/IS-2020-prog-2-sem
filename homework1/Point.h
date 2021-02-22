#ifndef HOMEWORK1_POINT_H
#define HOMEWORK1_POINT_H

#include <cmath>

class Point {
private:
  double x_;
  double y_;
public:
  Point();                                      // конструктор по-умолчанию
  Point(double x, double y);                    // конструктор от координат

  Point(const Point& other);                    // конструктор копирования
  Point& operator=(const Point& other);         // оператор присваивания
  ~Point() { }                                   // деструктор

  double getX() const;
  double getY() const;
  double getDistance(const Point& other) const;
};



#endif //HOMEWORK1_POINT_H
