#include "BouncyBallGame.hpp"
#include <iostream>
#include <functional>

BouncyBallGame::BouncyBallGame()
  : _window(sf::VideoMode(500, 500), "Bouncing Balls")
{ }

void BouncyBallGame::run() {
  
  _renderThread = std::thread(std::bind(&Game::render, this, &_window));
  _physicsThread = std::thread(&Game::handlePhysics, this);
  while(_window.isOpen()) {
    pollEvents(); // events must be handled in the main thread
  }
  _renderThread.join();
  _physicsThread.join();
}

void BouncyBallGame::pollEvents() {
  while(_window.pollEvent(_event)) {
    switch (_event.type) {
      case sf::Event::Closed:
        std::cout << "Closing!\n";
        _window.close();
      case sf::Event::LefClick:
        std::cout << "User left clicked at position...\n";
        BouncyBall bball = _bbf.make("interactable");
        addBall(bball);
      case ::sf::Event::RightClick:
          BouncyBall bball = _bbf.make("noninteractable");
          addBall(bball);
          std::cout << "User right clicked at position...\n";
    }
  }
}

void BouncyBallGame::render(sf::RenderWindow* window) {
  // each ball should be inherit sf::Drawable, so they can be drawn using window.draw()
  window->setActive(true);
  // I should probably put a mutex here?
  while (window->isOpen()) {
    window->clear(sf::Color::Black);
    for (auto& bball : _entities) {
      window->draw(bball);
    }
    window->display();
  }
  // cleanup mutex
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

