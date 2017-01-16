#include "Polygon.h"

Polygon::Polygon() {

}

Polygon::Polygon(const std::vector<Point>& points) {
  _points = points;
}

Polygon::Polygon(int n, Point* points) {
  for (int i = 0; i < n; i++) {
    _points.push_back(points[i]);
  }
}

Polygon::Polygon(const Polygon& other) {
  _points = other._points;
}

Polygon& Polygon::operator=(const Polygon& other) {
  _points = other._points;

  return *this;
}
