#ifndef APP_H
#define APP_H

#include "Point.h"

#include <vector>

class App {
  public:
    static App* Instance();
    void Start();

  private:
    App();
    ~App();
    App(const App& other);
    App& operator=(const App& other);

  private:
    std::vector<Point> pol1, pol2, hull;
};

#endif
