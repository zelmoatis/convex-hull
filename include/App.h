#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>

#include "Polygon.h"

#include <vector>

class App {
  public:
    static App* Instance();

    void Init();
    void Start();
    void Quit();

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
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    int _width;
    int _height;

    Polygon _pol1, _pol2, _hull;
    bool _isHullShown;
};

#endif
