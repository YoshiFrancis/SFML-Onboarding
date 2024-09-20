#include "bouncyball.hpp"
#include <iostream>

BouncyBall::BouncyBall(float radius, int red, int green, int blue, bool isInteractble) 
  : _sprite(radius), _interactable(isInteractble)
{
  _sprite.setFillColor(sf::Color(red, green, blue));
  if (!_interactable) {
    _sprite.setOutlineThickness(std::max(1.f, radius - 10));
    _sprite.setOutlineColor(sf::Color((blue % 10) + 79, green, red / 2));
  }
  if (isInteractble) {
      _sprite.setOrigin(radius/2, radius/2);
      _sprite.move(100, 100);
  } else {
    _sprite.setPosition(0, 0);
  }
  auto origin = _sprite.getOrigin();
  auto pos = _sprite.getPosition();
  auto global = _sprite.getGlobalBounds();
  auto global_pos = global.getPosition();


  std::cout << "Origin: (" << origin.x << ", " << origin.y << ")\n";
  std::cout << "Position: (" << pos.x << ", " << pos.y << ")\n";
  std::cout << "Global Position: (" << global_pos.x << ", " << global_pos.y << ")\n";
}

bool BouncyBall::isInteractble() const {
  return _interactable;
}

sf::Vector2f BouncyBall::getPosition() const {
  return _sprite.getPosition();
}

float BouncyBall::getRadius() const {
  return _sprite.getRadius();
}

void BouncyBall::setPosition(sf::Vector2f pos) {
  _sprite.setPosition(pos);
}

void BouncyBall::accelerate(sf::Vector2f acc) {
  _velocity += acc;
}

void BouncyBall::accelerateX(float x) {
  _velocity.x += x;
}

void BouncyBall::accelerateY(float y) {
  _velocity.y += y;
}

void BouncyBall::setVelocity(sf::Vector2f velocity) {
  _velocity = velocity;
}

void BouncyBall::setVelocityX(float x) {
  _velocity.x = x;
}

void BouncyBall::setVelocityY(float y) {
  _velocity.y = y;
}

void BouncyBall::rotate(float rad) {
  _sprite.rotate(rad);
}

void BouncyBall::move(sf::Vector2f pos) {
  _sprite.move(pos);
}

void BouncyBall::move() {
  std::cout << "Velocity: " << _velocity.x << ", " << _velocity.y << "\n";
  _sprite.move(_velocity);
}

void BouncyBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform = _sprite.getTransform();
  target.draw(_sprite, states);
  sf::FloatRect boundingBox = _sprite.getGlobalBounds();
  sf::RectangleShape box;
}

BouncyBall::~BouncyBall() {
}

