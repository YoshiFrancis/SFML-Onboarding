#ifndef BOUNCYBALLFACTOR_HPP_
#define BOUNCYBALLFACTOR_HPP_

#include <random>
#include "bouncyball.hpp"

class BouncyBallFactory {
public:
  BouncyBallFactory();
  BouncyBallFactory(BouncyBallFactory &&) = default;
  BouncyBallFactory(const BouncyBallFactory &) = default;
  BouncyBallFactory &operator=(BouncyBallFactory &&) = default;
  BouncyBallFactory &operator=(const BouncyBallFactory &) = default;
  ~BouncyBallFactory();

  BouncyBall create(bool isInteractable) const;
};

BouncyBall BouncyBallFactory::create(bool isInteractable) const {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(0,255);
  int red = dist(rng);
  int green = dist(rng);
  int blue = dist(rng);
  return BouncyBall(50.f, red, green, blue, isInteractable);
}

BouncyBallFactory::BouncyBallFactory() {
}

BouncyBallFactory::~BouncyBallFactory() {
}

#endif // !BOUNCYBALLFACTOR_HPP_
#define BOUNCYBALLFACTOR_HPP_

