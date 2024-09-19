#ifndef BOUNCYBALLFACTORY_HPP_
#define BOUNCYBALLFACTORY_HPP_

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

#endif // !BOUNCYBALLFACTORY_HPP_
