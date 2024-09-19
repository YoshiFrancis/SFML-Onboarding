#ifndef BOUNCYBALL_HPP_
#define BOUNCYBALL_HPP_

#include <SFML/Graphics.hpp>

// im thinking that bouncyball keeps track of its own velocity and the physics engine only tells it when to accelerate 
// or when to change velocity

class BouncyBall : public sf::Drawable {
private:
  bool _interactable; // in a real game, make it int to have 32 flags to decide what other objects it interacts with
  sf::CircleShape _sprite;
  sf::Vector2f _velocity;
public:
  BouncyBall(float radius, int red, int green, int blue, bool isInteractble);
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
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
