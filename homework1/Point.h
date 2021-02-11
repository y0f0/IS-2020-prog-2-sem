#ifndef HOMEWORK1_POINT_H
#define HOMEWORK1_POINT_H

#include <cmath>

class Point {
private:
  int X;
  int Y;
public:
  Point();                            // конструктор по-умолчанию
  Point(int x, int y);                // конструктор от координат
  Point(const Point& p);              // конструктор копирования
  Point& operator=(const Point& p);   // оператор присваивания
  int getX() const;
  int getY() const;
  double getDistance(const Point& p) const;
};



#endif //HOMEWORK1_POINT_H
