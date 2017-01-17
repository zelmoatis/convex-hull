#include "App.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

App::App() {

}

App::~App() {

}

App* App::Instance() {
  static App instance;

  return &instance;
}

void App::Init() {
  _width = SCREEN_WIDTH;
  _height = SCREEN_HEIGHT;

  if (SDL_Init(SDL_INIT_VIDEO) == 0) {
    _window = nullptr;
    _renderer = nullptr;

    SDL_CreateWindowAndRenderer(_width, _height, 0, &_window, &_renderer);
  }
}

void App::Start() {
  SDL_bool done = SDL_FALSE;

  while (!done) {
    SDL_Event event;

    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(_renderer);

    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    if (_isHullShown) {
      std::vector<Point> points = _hull.getPoints();
      std::vector<Line> lines = _hull.getLines();

      for (int i = 0; i < points.size(); i++) {
        SDL_RenderDrawPoint(_renderer, points[i].getX(), points[i].getY());
      }

      for (int i = 0; i < lines.size(); i++) {
        Point start = lines[i].getStartPoint();
        Point finish = lines[i].getFinishPoint();
        SDL_RenderDrawLine(_renderer, start.getX(), start.getY(),
            finish.getX(), finish.getY());
      }

      SDL_RenderPresent(_renderer);
    }

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }
    }
  }
}

void App::Quit() {
  if (_renderer) {
    SDL_DestroyRenderer(_renderer);
  }
  if (_window) {
    SDL_DestroyWindow(_window);
  }
}

void App::receivePolygons(const Polygon& pol1, const Polygon& pol2) {
  _pol1 = pol1;
  _pol2 = pol2;
}

void App::receiveHull(const Polygon& hull) {
  _hull = hull;
}

bool App::showHull(bool flip) {
  _isHullShown = flip;
}

bool App::isHullShown() {
  return _isHullShown;
}
