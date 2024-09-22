#include <iostream>
#include <functional>
#include "BouncyBallGame.hpp"

constexpr float VIEW_HEIGHT = 512.f;
constexpr float GRAVITY = .98f;
BouncyBallGame::BouncyBallGame()
  : _window(sf::VideoMode(VIEW_HEIGHT, VIEW_HEIGHT), "Bouncing Balls"), _view(sf::Vector2f(VIEW_HEIGHT/2, VIEW_HEIGHT/2), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT))
    ,_viewHeight(VIEW_HEIGHT)
{ 
  _window.setView(_view);
  _window.setFramerateLimit(60);
}

void BouncyBallGame::run() {
  sf::Clock clock;
  while(_window.isOpen()) {
    float deltaTime = clock.restart().asSeconds();
    pollEvents(); // events must be handled in the main thread
    handlePhysics(deltaTime);
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

void BouncyBallGame::handlePhysics(float deltaTime) {
  // simple start -> iterate through each ball and check if they interact with ball or window
  // more complex -> quad tree
  // for now, do noninteractable balls which only hit on window

  for (auto& bball : _entities) {
    bball._velocity.y += deltaTime * GRAVITY;
    for (auto& other : _entities) {
      if (&other == &bball)
        continue;
      collide(bball, other, deltaTime);
    }
  }
  
  for (auto& bball : _entities) {
    auto pos = bball.getPosition();
    if (pos.x - bball.getRadius() <= 0 || pos.x + bball.getRadius() >= 200) {
      bball._velocity.x *= -1;
    }
    if (pos.y + bball.getRadius() >= 256 && bball._velocity.y > 0) {
      bball._velocity.y *= -1;
    }
    
    bball.move();
  }
}

void BouncyBallGame::addBall(BouncyBall& ball) {
  // do stuff with mutexes...
  _entities.push_back(ball);
  // clean up mutexes
}

template <typename T>
float magVector(sf::Vector2<T> v1) {
  return std::sqrt(v1.x * v1.x + v1.y * v1.y);
}

bool BouncyBallGame::isColliding(BouncyBall& b1, BouncyBall& b2) const {
  if (!b1.isInteractable() || !b2.isInteractable())
      return false;
  sf::Vector2f dist = b1.getPosition() - b2.getPosition();
  float max_dist = b1.getRadius() + b2.getRadius();
  if (magVector(dist) <= max_dist) 
    return true;
  return false;
}

float dot(sf::Vector2f v1, sf::Vector2f v2) {
  return v1.x * v2.x + v1.y + v2.y;
}

template <typename T>
sf::Vector2f unitVector(sf::Vector2<T> v) {
  return v / magVector(v);
}

void BouncyBallGame::collide(BouncyBall& b1, BouncyBall& b2, float deltaTime) {

  sf::Vector2f posDiff = b2.getPosition() - b1.getPosition();
  float posDiffMag = magVector(posDiff);
  float overlap = posDiffMag - b1.getRadius() - b2.getRadius();
  if (overlap < -1) {
    auto offset_vector = overlap * .5f * unitVector(posDiff);
    b1.setPosition(b1.getPosition() + offset_vector);
    b2.setPosition(b2.getPosition() + -offset_vector);

    sf::Vector2f velDiff = b2.getVelocity() - b1.getVelocity();
    auto deltaVelb1 = dot(velDiff, posDiff) / posDiffMag * posDiff;
    auto deltaVelb2 = dot(velDiff, posDiff) / posDiffMag * posDiff;
    b1._velocity += deltaVelb1 * deltaTime;
    b2._velocity += -deltaVelb2 * deltaTime;
  }
}


