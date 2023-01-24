#pragma once

#include <cmath>
#include <ostream>

namespace cf {
class ExpEquation {
  double getBase() const { return base; }
  double getA() const { return a; }
  double getB() const { return b; }

  friend std::ostream &operator<<(std::ostream &os, ExpEquation &logEquation) {
    os << logEquation.getA() << " + " << logEquation.getB();
    if (logEquation.getBase() == exp(1))
      os << "e";
    else
      os << logEquation.getBase();
    os << "^(x)";
    return os;
  }

public:
  double base;
  double a, b;
};
} // namespace cf