#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"

#include <vector>

class Polygon {
  public:
    Polygon();
    Polygon(const std::vector<Point>& points);
    Polygon(int n, Point* points);
    Polygon(const Polygon& other);
    Polygon& operator=(const Polygon& other);

  private:
    std::vector<Point> _points;
};

#endif
