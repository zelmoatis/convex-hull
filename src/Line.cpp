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

Point Line::getStartPoint() {
  return _start;
}

Point Line::getFinishPoint() {
  return _finish;
}

void Line::setStartPoint(const Point& start) {
  _start = start;
}

void Line::setFinishPoint(const Point& finish) {
  _finish = finish;
}
