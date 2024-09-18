#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <thread>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "enemy.hpp"

class Game {

private:
  sf::RenderWindow _window;
  Player _player;
  Enemy _enemy;
  sf::Event _event;
  std::vector<sf::Drawable*> _entities;
  std::thread _renderThread;

public:
  Game();
  virtual void run();

private:
    virtual void update();
    virtual void pollEvents();
    virtual void render(sf::RenderWindow* _window);

};

#endif // !GAME_HPP
