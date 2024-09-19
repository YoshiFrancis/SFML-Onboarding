#ifndef BOUNCYBALL_HPP_
#define BOUNCYBALL_HPP_

#include <SFML/Graphics.hpp>

// im thinking that bouncyball keeps track of its own velocity and the physics engine only tells it when to accelerate 
// or when to change velocity

class BouncyBall {
private:
  bool _interactable; // in a real game, make it int to have 32 flags to decide what other objects it interacts with
  sf::CircleShape _sprite;
  sf::Vector2f _velocity;
public:
  BouncyBall(int radius, int red, int green, int blue, bool isInteractble);
  BouncyBall(BouncyBall &&) = default;
  BouncyBall(const BouncyBall &) = default;
  BouncyBall &operator=(BouncyBall &&) = default;
  BouncyBall &operator=(const BouncyBall &) = default;
  ~BouncyBall();

  bool isInteractble() const;
  sf::Vector2f getPosition() const;
  void accelerate(sf::Vector2f acc);
  void accelerateX(int x);
  void accelerateY(int y);
  void setVelocity(sf::Vector2f velocity);
  void setVelocityX(int x);
  void setVelocityY(int y);
  void move(sf::Vector2f pos);

private:

  
};

BouncyBall::BouncyBall(float radius, int red, int green, int blue, bool isInteractble) 
  : _sprite(radius), _interactable(isInteractble)
{
  _sprite.setFillColor(sf::Color(red, green, blue));
  if (!_interactable) {
    _sprite.setOutlineThickness(std::max(1, radius - 10));
    _sprite.setOutlineColor(sf::Color((blue % 10) + 79, green, red / 2));
  }
}

bool BouncyBall::isInteractble() const {
  return _interactable;
}

sf::Vector2f BouncyBall::getPosition() const {
  return _sprite.getPosition();
}

void BouncyBall::move(sf::Vector2f pos) {
  _sprite.move(pos);
}

BouncyBall::~BouncyBall() {
}
#endif // !BOUNCYBALL_HPP_

