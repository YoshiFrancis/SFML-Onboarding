#include "player.hpp"
#include <iostream>

Player::Player(std::string name) : _name(name), _speed(1.f)
{
  if (!_texture.loadFromFile("player.png")) {
    std::cout << "failed to load player.png\n";
  }
  _sprite = sf::Sprite(_texture);
}

void Player::move(int x, int y) {
  _sprite.move(x * _speed, y * _speed);
}

void Player::setSpeed(float speed) { _speed = speed; }

float Player::getSpeed() const {
  return _speed;
}

const sf::Vector2f& Player::getPosition() const {
  return _sprite.getPosition();
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform = _sprite.getTransform();
  target.draw(_sprite, states);
}
