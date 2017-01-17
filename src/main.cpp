#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>

#include "App.h"
#include "Point.h"

const int MAX_N = 120005;

int n;
std::vector< Point > v1;
std::vector< Point > v2;

std::vector< Line > l1;
std::vector< Line > l2;

Point v[MAX_N];
Point st[MAX_N];
int head;

double det(const Point& A, const Point& B, const Point& C) {
  return (B._x - A._x) * (C._y - A._y) - (B._y - A._y) * (C._x - A._x);
}

bool cmp(const Point& A, const Point& B) {
  return det(v[1], A, B) < 0;
}

int main(int argc, char** argv) {

  App* app = App::Instance();
  app->Init();

  /* Default file number */
  std::string file_number = "1";
  if (argc > 1) {
    file_number = argv[1];
  }
  std::ifstream fin("input/date" + file_number + ".in");

  fin >> n;
  for (int i = 1; i <= n; i++) {
    double x, y;
    fin >> x >> y;
    Point newPoint;
    newPoint.setX( x * 50 + 100 );
    newPoint.setY( y * 50 + 100 );
    v1.push_back( newPoint );

    v[ i ].setX( x * 50 + 100 );
    v[ i ].setY( y * 50 + 100 );

  }

  for ( int i = 1; i <= n; i++ ) {
    double x, y;
    fin >> x >> y;

    Line newLine;
    newLine.setStartPoint( v1[ x - 1 ] );
    newLine.setFinishPoint( v1[ y - 1 ] );

    l1.push_back( newLine );
  }

  fin >> n;
  for (int i = 1; i <= n; i++) {
    double x, y;
    fin >> x >> y;

    Point newPoint;
    newPoint.setX( x * 50 + 100 );
    newPoint.setY( y * 50 + 100 );
    v2.push_back( newPoint );

    v[ i + n ].setX(x * 50 + 100);
    v[ i + n ].setY(y * 50 + 100);
  }

  for ( int i = 1; i <= n; i++ ) {
    double x, y;
    fin >> x >> y;

    Line newLine;
    newLine.setStartPoint( v2[ x - 1 ] );
    newLine.setFinishPoint( v2[ y - 1] );

    l2.push_back( newLine );
  }

  int pos = 1;
  for (int i = 2; i <= n * 2; i++) {
    if (v[i] < v[pos]) {
      pos = i;
    }
  }
  std::swap(v[1], v[pos]);
  std::sort(v + 2, v + n * 2 + 1, cmp);

  st[1] = v[1];
  st[2] = v[2];
  head = 2;
  for (int i = 3; i <= n * 2; i++) {
    while (head >= 2 && det(st[head - 1], st[head], v[i]) > 0) {
      --head;
    }

    st[++head] = v[i];
  }

  Line lines[head + 1];
  for (int i = head, j = 1; i >= 1; i--, j++) {
    lines[j].setStartPoint(st[i]);
    if (i - 1 >= 1) {
      lines[j].setFinishPoint(st[i - 1]);
    } else {
      lines[j].setFinishPoint(st[head]);
    }
  }

  Polygon hull(n * 2, v, head, lines);
  Polygon p1( v1, l1 );
  Polygon p2( v2, l2 );

  app->receivePolygons( p1, p2 );

  app->receiveHull(hull);
  app->showHull(false);

  app->Start();

  app->Quit();

  return 0;
}
