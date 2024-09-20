#include <iostream>
#include <functional>
#include "BouncyBallGame.hpp"

constexpr float VIEW_HEIGHT = 512.f;
BouncyBallGame::BouncyBallGame()
  : _window(sf::VideoMode(VIEW_HEIGHT, VIEW_HEIGHT), "Bouncing Balls"), _view(sf::Vector2f(VIEW_HEIGHT/2, VIEW_HEIGHT/2), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT))
    ,_viewHeight(VIEW_HEIGHT)
{ 
  _window.setView(_view);
}

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
      case sf::Event::Resized:
        std::cout << "Resizing!\n";
        _window.setView(sf::View(sf::FloatRect(0, 0, _event.size.width, _event.size.height)));
      case sf::Event::MouseButtonReleased:
        sf::Vector2f mouse_pos = sf::Vector2f(_event.mouseButton.x, _event.mouseButton.y);
        sf::Vector2i new_mouse_pos = sf::Mouse::getPosition(_window);
        mouse_pos.x /= 2;
        mouse_pos.y /= 2;
        if (_event.mouseButton.button == sf::Mouse::Left) {
          BouncyBall bball = _bbf.create(true);
          bball.setPosition(mouse_pos);
          addBall(bball);
        } else if (_event.mouseButton.button == sf::Mouse::Right) {
          BouncyBall bball = _bbf.create(false);
          addBall(bball);
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

