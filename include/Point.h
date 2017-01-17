#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
  public:
    Point();
    Point(double x, double y);
    Point(const Point& other);
    Point& operator=(const Point& other);

    bool operator<(const Point& other);

    friend bool cmp(const Point& A, const Point& B);
    friend double det(const Point& A, const Point& B, const Point& C);
    friend std::ostream& operator<<(std::ostream& out, const Point& point);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

  private:
    double _x;
    double _y;
};

#endif
