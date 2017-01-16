#ifndef APP_H
#define APP_H

class App {
  public:
    static App* Instance();
    void Start();

  private:
    App();
    ~App();
    App(const App& other);
    App& operator=(const App& other);
};

#endif
