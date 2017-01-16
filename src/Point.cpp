#include "Point.h"

Point::Point() {
  x = 0;
  y = 0;
}

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

double det(const Point& A, const Point& B, const Point& C) {
  return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

bool cmp(const Point& O, const Point& A, const Point& B) {
  return det(O, A, B) < 0;
}
