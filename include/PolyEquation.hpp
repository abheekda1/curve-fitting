#pragma once

#include <ostream>
#include <vector>

namespace cf {
template <class T> class PolyEquation {
public:
  PolyEquation(int order) : order(order) { a.reserve(order + 1); }
  PolyEquation(int order, std::vector<T> a) : order(order), a(a){};
  PolyEquation(std::vector<T> a) : order(a.size() - 1), a(a){};

  int getOrder() const { return order; }

  std::vector<T> getA() const { return a; }

  friend std::ostream &operator<<(std::ostream &os,
                                  PolyEquation<T> &polyEquation) {
    for (int i = (int)polyEquation.getA().size() - 1; i >= 0; i--) {
      os << polyEquation.getA().at(i) << (i > 0 ? "x" : "")
         << (i > 1 ? "^" : "");
      if (i > 1)
        os << i;
      if (i > 0)
        os << " + ";
    }

    return os;
  }

private:
  int order;
  std::vector<T> a;
};
} // namespace cf
