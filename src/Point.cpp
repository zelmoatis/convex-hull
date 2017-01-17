#include "Point.h"

#include <iostream>

Point::Point() {
  _x = 0;
  _y = 0;
}

Point::Point(double x, double y) {
  _x = x;
  _y = y;
}

Point::Point(const Point& other) {
  _x = other._x;
  _y = other._y;
}

Point& Point::operator=(const Point& other) {
  _x = other._x;
  _y = other._y;

  return *this;
}

bool Point::operator<(const Point& other) {
  if (_x == other._x) {
    return _y < other._y;
  }
  return _x < other._x;
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
  out << point._x << " " << point._y;

  return out;
}

double Point::getX() const {
  return _x;
}

double Point::getY() const {
  return _y;
}

void Point::setX(double x) {
  _x = x;
}

void Point::setY(double y) {
  _y = y;
}
