#ifndef BOUNCYBALL_HPP_
#define BOUNCYBALL_HPP_

#include <SFML/Graphics.hpp>

// im thinking that bouncyball keeps track of its own velocity and the physics engine only tells it when to accelerate 
// or when to change velocity

class BouncyBall : public sf::Drawable {
private:
  bool _interactable; // in a real game, make it int to have 32 flags to decide what other objects it interacts with
  sf::CircleShape _sprite;
  float _maxSpeed = 1.f;
public:
  sf::Vector2f _velocity;
  BouncyBall(float radius, int red, int green, int blue, bool isInteractble);
  BouncyBall(BouncyBall &&) = default;
  BouncyBall(const BouncyBall &) = default;
  BouncyBall &operator=(BouncyBall &&) = default;
  BouncyBall &operator=(const BouncyBall &) = default;
  ~BouncyBall();

  bool isInteractable() const;
  sf::Vector2f getPosition() const;
  float getRadius() const;
  sf::Vector2f getVelocity() const;
  void setPosition(sf::Vector2f pos);
  void accelerate(sf::Vector2f acc);
  void accelerateX(float x);
  void accelerateY(float y);
  void setVelocity(sf::Vector2f velocity);
  void setVelocityX(float x);
  void setVelocityY(float y);
  void rotate(float rad);
  void move(sf::Vector2f pos);
  void move();
  
private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
