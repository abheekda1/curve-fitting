#pragma once

#include <cmath>
#include <ostream>

namespace cf {
class LogEquation {
public:
  LogEquation(double base, double a, double b) : base(base), a(a), b(b) {}

  double getBase() const { return base; }
  double getA() const { return a; }
  double getB() const { return b; }

  friend std::ostream &operator<<(std::ostream &os, LogEquation &logEquation) {
    os << logEquation.getA() << " + " << logEquation.getB();
    if (logEquation.getBase() == exp(1))
      os << "ln";
    else
      os << "log_" << logEquation.getBase();
    os << "(x)";
    return os;
  }

private:
  double base = exp(1);
  double a, b;
};
} // namespace cf