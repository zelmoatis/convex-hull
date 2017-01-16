#include "App.h"

#include <iostream>

int main(int argc, char** argv) {
  App* app = App::Instance();

  /* app->Start(); */

  Point p1(2, 3);
  Point p2(6, 9);
  Point p3(10, -15);

  std::cout << det(p1, p2, p3);

  return 0;
}
