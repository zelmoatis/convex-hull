#ifndef POINT_H
#define POINT_H

class Point {
  public:
    Point();
    Point(double x, double y);

    friend bool cmp(const Point& O, const Point& A, const Point& B);
    friend double det(const Point& A, const Point& B, const Point& C);

  private:
    double x;
    double y;
};

#endif
