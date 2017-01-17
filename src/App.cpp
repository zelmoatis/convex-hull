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

    if (_isHullShown) {

      std::vector<Point> points = _hull.getPoints();
      std::vector<Line> lines = _hull.getLines();

      SDL_SetRenderDrawColor(_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      for (int i = 0; i < lines.size(); i++) {
        Point start = lines[i].getStartPoint();
        Point finish = lines[i].getFinishPoint();
        SDL_RenderDrawLine(_renderer, start.getX(), start.getY(),
            finish.getX(), finish.getY());
      }

      SDL_SetRenderDrawColor(_renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
      for (int i = 0; i < points.size(); i++) {
        SDL_RenderDrawPoint(_renderer, points[i].getX(), points[i].getY());
        SDL_RenderDrawPoint(_renderer, points[i].getX() + 1, points[i].getY());
        SDL_RenderDrawPoint(_renderer, points[i].getX() - 1, points[i].getY());
        SDL_RenderDrawPoint(_renderer, points[i].getX(), points[i].getY() + 1 );
        SDL_RenderDrawPoint(_renderer, points[i].getX(), points[i].getY() - 1 );
        SDL_RenderDrawPoint(_renderer, points[i].getX() + 1, points[i].getY() + 1 );
        SDL_RenderDrawPoint(_renderer, points[i].getX() + 1, points[i].getY() - 1 );
        SDL_RenderDrawPoint(_renderer, points[i].getX() - 1, points[i].getY() + 1 );
        SDL_RenderDrawPoint(_renderer, points[i].getX() - 1, points[i].getY() - 1 );
      }

      SDL_RenderPresent(_renderer);

    } else {
      std::vector< Line > l1 = _pol1.getLines();
      std::vector< Line > l2 = _pol2.getLines();

      std::vector< Point > v1 = _pol1.getPoints();
      std::vector< Point > v2 = _pol2.getPoints();

      SDL_SetRenderDrawColor(_renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
      for (int i = 0; i < l1.size(); i++) {
        Point start  = l1[i].getStartPoint();
        Point finish = l1[i].getFinishPoint();
        SDL_RenderDrawLine(_renderer, start.getX(), start.getY(),
            finish.getX(), finish.getY());
      }

      SDL_SetRenderDrawColor(_renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
      for (int i = 0; i < v1.size(); i++) {
        SDL_RenderDrawPoint(_renderer, v1[i].getX(), v1[i].getY());
        SDL_RenderDrawPoint(_renderer, v1[i].getX() + 1, v1[i].getY());
        SDL_RenderDrawPoint(_renderer, v1[i].getX() - 1, v1[i].getY());
        SDL_RenderDrawPoint(_renderer, v1[i].getX(), v1[i].getY() + 1 );
        SDL_RenderDrawPoint(_renderer, v1[i].getX(), v1[i].getY() - 1 );
        SDL_RenderDrawPoint(_renderer, v1[i].getX() + 1, v1[i].getY() + 1 );
        SDL_RenderDrawPoint(_renderer, v1[i].getX() + 1, v1[i].getY() - 1 );
        SDL_RenderDrawPoint(_renderer, v1[i].getX() - 1, v1[i].getY() + 1 );
        SDL_RenderDrawPoint(_renderer, v1[i].getX() - 1, v1[i].getY() - 1 );
      }

      SDL_SetRenderDrawColor(_renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
      for (int i = 0; i < l2.size(); i++) {
        Point start  = l2[i].getStartPoint();
        Point finish = l2[i].getFinishPoint();
        SDL_RenderDrawLine(_renderer, start.getX(), start.getY(),
            finish.getX(), finish.getY());
      }

      SDL_SetRenderDrawColor(_renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
      for (int i = 0; i < v2.size(); i++) {
        SDL_RenderDrawPoint(_renderer, v2[i].getX(), v2[i].getY());
        SDL_RenderDrawPoint(_renderer, v2[i].getX() + 1, v2[i].getY());
        SDL_RenderDrawPoint(_renderer, v2[i].getX() - 1, v2[i].getY());
        SDL_RenderDrawPoint(_renderer, v2[i].getX(), v2[i].getY() + 1 );
        SDL_RenderDrawPoint(_renderer, v2[i].getX(), v2[i].getY() - 1 );
        SDL_RenderDrawPoint(_renderer, v2[i].getX() + 1, v2[i].getY() + 1 );
        SDL_RenderDrawPoint(_renderer, v2[i].getX() + 1, v2[i].getY() - 1 );
        SDL_RenderDrawPoint(_renderer, v2[i].getX() - 1, v2[i].getY() + 1 );
        SDL_RenderDrawPoint(_renderer, v2[i].getX() - 1, v2[i].getY() - 1 );
      }

      SDL_RenderPresent(_renderer);
    }

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      } else {
        if( event.type == SDL_KEYDOWN ) {
            //Select surfaces based on key press
            switch( event.key.keysym.sym ) {
                case SDLK_p:
                  _isHullShown = !_isHullShown;
                break;

                case SDLK_ESCAPE:
                  done = SDL_TRUE;
                break;
            }
          }
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
