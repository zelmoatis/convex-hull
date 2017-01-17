#ifndef POLYGON_H
#define POLYGON_H

#include "Line.h"

#include <vector>

class Polygon {
  public:
    Polygon();
    Polygon(const std::vector<Point>& points, const std::vector<Line>& lines);
    Polygon(int n, Point* points, int m, Line* lines);
    Polygon(const Polygon& other);
    Polygon& operator=(const Polygon& other);

    std::vector<Point> getPoints();
    std::vector<Line> getLines();

  private:
    std::vector<Point> _points;
    std::vector<Line> _lines;
};

#endif
