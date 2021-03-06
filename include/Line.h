#ifndef LINE_H
#define LINE_H

#include "Point.h"

#include <vector>

class Line {
  public:
    Line();
    Line(const Point& start, const Point& finish);
    Line(const Line& other);
    Line& operator=(const Line& other);

    Point getStartPoint();
    Point getFinishPoint();

    void setStartPoint(const Point& start);
    void setFinishPoint(const Point& finish);

  private:
    Point _start;
    Point _finish;
};

#endif
