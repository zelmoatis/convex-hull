#ifndef POINT_H
#define POINT_H

class Point {
  public:
    Point();
    Point(double x, double y);
    Point(const Point& other);
    Point& operator=(const Point& other);

    friend bool cmp(const Point& O, const Point& A, const Point& B);
    friend double det(const Point& A, const Point& B, const Point& C);

    double getX();
    double getY();

  private:
    double _x;
    double _y;
};

#endif
