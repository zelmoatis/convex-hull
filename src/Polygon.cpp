#include "Polygon.h"

Polygon::Polygon() {

}

Polygon::Polygon(const std::vector<Point>& points, const std::vector<Line>& lines) {
  _points = points;
  _lines = lines;
}

Polygon::Polygon(int n, Point* points, int m, Line* lines) {
  for (int i = 1; i <= n; i++) {
    _points.push_back(points[i]);
  }
  for (int i = 1; i <= m; i++) {
    _lines.push_back(lines[i]);
  }
}

Polygon::Polygon(const Polygon& other) {
  _points = other._points;
  _lines = other._lines;
}

Polygon& Polygon::operator=(const Polygon& other) {
  _points = other._points;
  _lines = other._lines;

  return *this;
}

std::vector<Point> Polygon::getPoints() {
  return _points;
}

std::vector<Line> Polygon::getLines() {
  return _lines;
}
