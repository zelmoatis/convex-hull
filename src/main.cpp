#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>

#include "App.h"
#include "Point.h"

std::ifstream fin("input/date1.in");

const int MAX_N = 120005;

int n;
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

  fin >> n;
  for (int i = 1; i <= n; i++) {
    double x, y;
    fin >> x >> y;
    /* v[i].setX(x); */
    /* v[i].setY(y); */
    v[i].setX(x * 50 + 100);
    v[i].setY(y * 50 + 100);
  }

  int pos = 1;
  for (int i = 2; i <= n; i++) {
    if (v[i] < v[pos]) {
      pos = i;
    }
  }
  std::swap(v[1], v[pos]);
  std::sort(v + 2, v + n + 1, cmp);

  st[1] = v[1];
  st[2] = v[2];
  head = 2;
  for (int i = 3; i <= n; i++) {
    while (head >= 2 && det(st[head - 1], st[head], v[i]) > 0) {
      --head;
    }

    st[++head] = v[i];
  }

  std::cout << std::fixed;
  std::cout << head << "\n";
  for (int i = head; i >= 1; i--) {
    std::cout << std::setprecision(9) << st[i] << "\n";
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

  for (int i = 1; i <= 6; i++) {
    std::cout << lines[i].getStartPoint() << " " << lines[i].getFinishPoint() << "\n";
  }

  Polygon hull(n, v, head, lines);

  app->receiveHull(hull);
  app->showHull(true);

  app->Start();

  app->Quit();

  return 0;
}
