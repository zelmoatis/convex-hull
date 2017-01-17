#ifndef POINT_H
#define POINT_H

#if defined(__linux__) || defined(__APPLE__)
  #include <SDL2/SDL.h>
#elif defined(_WIN32)
  #include <SDL.h>
#endif

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

    void draw(SDL_Renderer* renderer);

  private:
    double _x;
    double _y;
};

#endif
