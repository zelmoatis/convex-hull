#include "Line.h"

Line::Line() :
  _start(), _finish()
{

}

Line::Line(const Point& start, const Point& finish) {
  _start = start;
  _finish = finish;
}

Line::Line(const Line& other) {
  _start = other._start;
  _finish = other._finish;
}

Line& Line::operator=(const Line& other) {
  _start = other._start;
  _finish = other._finish;

  return *this;
}
