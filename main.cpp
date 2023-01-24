#include <iostream>

#include "matrix.hpp"

int main() {
  // clang-format off
  int data[] = {
      4,  3,  2, 2,
      0,  1, -3, 3,
      0, -1,  3, 3,
      0,  3,  1, 1,
  };
  // clang-format on

  cf::matrix<int> m(4, 4, data);
  std::cout << m.getDeterminant() << std::endl;
}