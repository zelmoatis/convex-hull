#ifndef APP_H
#define APP_H

#if defined(__linux__) || defined(__APPLE__)
  #include <SDL2/SDL.h>
#elif defined(_WIN32)
  #include <SDL.h>
#endif

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
