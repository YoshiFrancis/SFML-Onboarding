#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable 
{
private:
  sf::Texture _texture;
  sf::Sprite _sprite;
  std::string _name;
  float _speed;

public:
  Player(std::string name="Yoshi");

  void move(int x, int y);
  void setSpeed(float speed);
  float getSpeed() const;
  const sf::Vector2f& getPosition() const;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !PLAYER_HPP
