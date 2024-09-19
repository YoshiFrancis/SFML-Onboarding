#include "bouncyball.hpp"

BouncyBall::BouncyBall(float radius, int red, int green, int blue, bool isInteractble) 
  : _sprite(radius), _interactable(isInteractble)
{
  _sprite.setFillColor(sf::Color(red, green, blue));
  if (!_interactable) {
    _sprite.setOutlineThickness(std::max(1.f, radius - 10));
    _sprite.setOutlineColor(sf::Color((blue % 10) + 79, green, red / 2));
  }
}

bool BouncyBall::isInteractble() const {
  return _interactable;
}

sf::Vector2f BouncyBall::getPosition() const {
  return _sprite.getPosition();
}

void BouncyBall::accelerate(sf::Vector2f acc) {
  _velocity += acc;
}

void BouncyBall::accelerateX(int x) {
  _velocity.x += x;
}

void BouncyBall::accelerateY(int y) {
  _velocity.y += y;
}

void BouncyBall::setVelocity(sf::Vector2f velocity) {
  _velocity = velocity;
}

void BouncyBall::setVelocityX(int x) {
  _velocity.x = x;
}

void BouncyBall::setVelocityY(int y) {
  _velocity.y = y;
}

void BouncyBall::move(sf::Vector2f pos) {
  _sprite.move(_velocity);
}

void BouncyBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform = _sprite.getTransform();
  target.draw(_sprite, states);
}

BouncyBall::~BouncyBall() {
}

