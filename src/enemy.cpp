#include "enemy.hpp"

Enemy::Enemy() : _sprite(50.f)
{
  _sprite.setFillColor(sf::Color::White);
}

void Enemy::setVelocity(sf::Vector2f velocity) {
  _velocity = velocity;
}

const sf::Vector2f& Enemy::getPosition() const {
  return _sprite.getPosition();
}

void Enemy::move() {
  _sprite.move(_velocity);
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform = _sprite.getTransform();
  target.draw(_sprite, states);
}
