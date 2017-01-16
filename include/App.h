#ifndef APP_H
#define APP_H

#include "Polygon.h"

#include <vector>

class App {
  public:
    static App* Instance();

    void Init(int n, int m);
    void Start();

    void receivePolygons(const Polygon& pol1, const Polygon& pol2);
    void receiveHull(const Polygon& hull);

    bool showHull(bool flip);
    bool isHullShown();

  private:
    App();
    ~App();
    App(const App& other);
    App& operator=(const App& other);

  private:
    Polygon _pol1, _pol2, _hull;
    bool _isHullShown;
};

#endif
