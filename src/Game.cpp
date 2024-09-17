#include "Game.hpp"
#include <iostream>
#include <functional>

Game::Game() 
  : _window(sf::VideoMode(500, 500), "Yoshi's Screen"), _player("Yoshi")
{
  _entities.push_back(&_player);
  _entities.push_back(&_enemy);
}

/*
 *
 * The run function keeps track of all the threads runnning throughout the Game
 * It was reccommended (a must of macOS) that
 * the event thread runs in the main threads. All other
 * handlers can be done in other threads, like Physics, 
 * logic, and rendering.
 *
 * What I have to figure out is how to communicate between
 * threads as each thread will need info from one another.
 * I would imagine that at least.
 */
void Game::run() {
  _window.setActive(false);
  _renderThread = std::thread(std::bind(&Game::render, this, &_window));
  while (_window.isOpen()) {
    update();
  }
  _renderThread.join();
}

void Game::update() {
  pollEvents();
  auto enemyPos = _enemy.getPosition();
  auto playerPos = _player.getPosition();
  std::cout << "Enemy: " << enemyPos.x << " " << enemyPos.y << "\n";
  std::cout << "Player: " << playerPos.x << " " << playerPos.y << "\n";
  sf::Vector2f enemyMovement;
  if ((playerPos.x - enemyPos.x) * (playerPos.x - enemyPos.x) <= 10)
    enemyMovement.x = .005f;
  if ((playerPos.y - enemyPos.y) * (playerPos.y - enemyPos.y) <= 10)
    enemyMovement.y = .005f;
  
  _enemy.setVelocity(enemyMovement);
  _enemy.move();
}

void Game::render(sf::RenderWindow* window) {
  window->setActive(true);
  while (window->isOpen()) {
    window->clear(sf::Color::Blue);
    for (sf::Drawable* entity: _entities) {
      window->draw(*entity);
    }
    window->display();
  }
}

void Game::pollEvents() { 
  while(_window.pollEvent(_event)) {
    switch (_event.type) {
      case sf::Event::Closed:
        std::cout << "Closing!\n";
        _window.close();
      case sf::Event::KeyPressed:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
          _window.close();
        int x = 0;
        int y = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          x = -1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
          x = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
          y = -1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
          y = 1;
        _player.move(x, y);
    }
  }
}
