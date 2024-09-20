#include <iostream>
#include <functional>
#include "BouncyBallGame.hpp"

BouncyBallGame::BouncyBallGame()
  : _window(sf::VideoMode(500, 500), "Bouncing Balls")
{ }

void BouncyBallGame::run() {
  while(_window.isOpen()) {
    pollEvents(); // events must be handled in the main thread
    handlePhysics();
    render();
  }
}

void BouncyBallGame::pollEvents() {
  while(_window.pollEvent(_event)) {
    switch (_event.type) {
      case sf::Event::Closed:
        std::cout << "Closing!\n";
        _window.close();
      case sf::Event::MouseButtonReleased:
        sf::Vector2f mouse_pos = sf::Vector2f(_event.mouseButton.x, _event.mouseButton.y);
        sf::Vector2i new_mouse_pos = sf::Mouse::getPosition(_window);
        mouse_pos.x /= 2;
        mouse_pos.y /= 2;
        std::cout << "User clicked at old position (" << mouse_pos.x << ", " << mouse_pos.y << ")\n";
        std::cout << "User clicked at new position (" << new_mouse_pos.x / 2 << ", " << new_mouse_pos.y / 2<< ")\n";
        if (_event.mouseButton.button == sf::Mouse::Left) {
          std::cout << "User left clicked at position...\n";
          BouncyBall bball = _bbf.create(true);
          bball.setPosition(mouse_pos);
          addBall(bball);
        } else if (_event.mouseButton.button == sf::Mouse::Right) {
          BouncyBall bball = _bbf.create(false);
          addBall(bball);
          std::cout << "User right clicked at position...\n";
        }
    }
  }
}

void BouncyBallGame::render() {
  // each ball should be inherit sf::Drawable, so they can be drawn using window.draw()
  _window.clear(sf::Color::Black);
  for (auto& bball : _entities) {
    _window.draw(bball);
  }
  _window.display();
}

void BouncyBallGame::handlePhysics() {
  // simple start -> iterate through each ball and check if they interact with ball or window
  // more complex -> quad tree
  // for now, do noninteractable balls which only hit on window

}

void BouncyBallGame::addBall(BouncyBall& ball) {
  // do stuff with mutexes...
  _entities.push_back(ball);
  // clean up mutexes
}

