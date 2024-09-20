#ifndef BOUNCYBALLGAME_HPP_
#define BOUNCYBALLGAME_HPP_

#include <thread>
#include <vector>
#include <SFML/Graphics.hpp>
#include "bouncyballfactory.hpp"

/*
 * Started September 17, 2024
 * Ended September 19, 2024
 *
 * Description:
 * Wehever a user clicks, a bouncy ball is created. Bouncy balls have the ability to react with one another, depending
 * on the user. If the user right clicks, a non-interactble bouncy ball spawns. A left-click spawns a ball which interacts
 * with other interactable bouncy balls. All balls will bounce on each side of the window. Gravity will be applied to
 * pull downward (toward the bottom of the screen) on balls.
 *
 * Reason:
 * Practice SFML
 * Practice moving objects
 * Practice interacting between objects
 * Practice making abstract factory for creating objects
 * SFML onboarding toward making Brawlmon (whatever that game will be called!)
 *
 *
 * TODO:  
 * DONE - settup BouncyBallFactory class
 * DONE - settup BouncyBall class
 * DONE - Render balls to screen with a click 
 *  - will have to mess around with views due to balls not scaling with window size
 *  - technically not necessary if I never mess with window size, but should be great introduction to views
 * TODO finish handlePhysics() for non-interactble
 * TODO get simulation up and running for non-interactable balls
 * TODO implement handlePhysics for interactable balls using linear iterations
 * TODO get simulation up and runnning for interactable balls using linear iterations
 * TODO implement handlePhysics using quad-tree
 * TODO get simulation up and running and finish off project
 *
 *
 */


class BouncyBallGame {

private:
  sf::RenderWindow _window;
  sf::View _view;
  int _viewHeight;
  float _prevAspectRatio = 0;
  sf::Event _event;
  std::vector<BouncyBall> _entities;
  std::thread _physicsThread;
  std::thread _renderThread;
  BouncyBallFactory _bbf;

public:
  BouncyBallGame();
  void run();

private:
  void pollEvents();
  void render();
  void handlePhysics(float deltaTime);
  void addBall(BouncyBall& ball);

};

#endif // !BOUNCYBALLGAME_HPP_
