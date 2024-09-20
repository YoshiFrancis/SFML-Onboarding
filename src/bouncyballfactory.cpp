#include "bouncyballfactory.hpp"

BouncyBall BouncyBallFactory::create(bool isInteractable) const {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(0,255);
  int red = dist(rng);
  int green = dist(rng);
  int blue = dist(rng);
  return BouncyBall(10.f, red, green, blue, isInteractable);
}

BouncyBallFactory::BouncyBallFactory() {
}

BouncyBallFactory::~BouncyBallFactory() {
}


