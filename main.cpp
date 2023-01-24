#include <iostream>

#include "Dataset.hpp"
#include "Matrix.hpp"

int main() {
  // clang-format off
  int data[] = {
      4,  3,  2, 2,
      0,  1, -3, 3,
      0, -1,  3, 3,
      0,  3,  1, 1,
  };
  // clang-format on

  cf::Matrix<int> m(4, 4, data);
  std::cout << m.getDeterminant() << std::endl;

  double x[] = {-3, -2, -1, -0.2, 1, 3};
  double y[] = {0.9, 0.8, 0.4, 0.2, 0.1, 0};
  cf::Dataset<double> d(6, x, y);
  std::vector<double> quadFit = d.PolyFit(2);
  for (int i = (int)quadFit.size() - 1; i >= 0; i--) {
    std::cout << quadFit.at(i) << (i > 0 ? "x" : "") << (i > 1 ? "^" : "");
    if (i > 1)
      std::cout << i;
    if (i > 0)
      std::cout << " + ";
  }
  std::cout << std::endl;
}