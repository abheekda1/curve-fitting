#pragma once

#include <cmath>

namespace cf {
class LogEquation {
public:
  LogEquation(double base, double a, double b) : base(base), a(a), b(b) {}

private:
  double base = exp(1);
  double a, b;
};
} // namespace cf