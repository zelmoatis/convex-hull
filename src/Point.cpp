#include "Point.h"

Point::Point() {
  _x = 0;
  _y = 0;
}

Point::Point(double x, double y) {
  this->_x = x;
  this->_y = y;
}

double det(const Point& A, const Point& B, const Point& C) {
  return (B._x - A._x) * (C._y - A._y) - (B._y - A._y) * (C._x - A._x);
}

bool cmp(const Point& O, const Point& A, const Point& B) {
  return det(O, A, B) < 0;
}

double Point::getX() {
  return _x;
}

double Point::getY() {
  return _y;
}
