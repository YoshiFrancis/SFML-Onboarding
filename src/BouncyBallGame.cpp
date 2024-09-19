#include <iostream>
#include <functional>
#include "BouncyBallGame.hpp"

BouncyBallGame::BouncyBallGame()
  : _window(sf::VideoMode(500, 500), "Bouncing Balls")
{ }

void BouncyBallGame::run() {
  while(_window.isOpen()) {
    pollEvents(); // events must be handled in the main thread
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      std::cout << "User left clicked at position...\n";
      BouncyBall bball = _bbf.create(true);
      addBall(bball);
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
      BouncyBall bball = _bbf.create(false);
      addBall(bball);
      std::cout << "User right clicked at position...\n";
    }
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

