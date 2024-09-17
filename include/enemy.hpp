#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>

class Enemy : public sf::Drawable
{
private:
  sf::Vector2f _velocity;
  sf::CircleShape _sprite;

public:
  Enemy();
  void setVelocity(sf::Vector2f velocity);
  const sf::Vector2f& getPosition() const;
  void move();
private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !ENEMY_H_
