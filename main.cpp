#include <iostream>

#include "Dataset.hpp"
#include "ExpEquation.hpp"
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
  std::cout << m << std::endl;
  std::cout << "determinant: " << m.getDeterminant() << std::endl;

  std::cout << "5x5 identity:\n" << cf::Matrix<int>::identity(5) << std::endl;

  double x1[] = {-3, -2, -1, -0.2, 1, 3};
  double y1[] = {0.9, 0.8, 0.4, 0.2, 0.1, 0};
  cf::Dataset<double> d1(6, x1, y1);
  cf::PolyEquation<double> quadFit = d1.PolyFit(2);
  std::cout << quadFit << std::endl;

  double x2[] = {3, 2, 1, 0.2};
  double y2[] = {0.9, 0.8, 0.4, 0.2};
  cf::Dataset<double> d2(4, x2, y2);
  cf::LogEquation lnFit = d2.LogFit();
  std::cout << lnFit << std::endl;

  double x3[] = {0, 2, 4, 5, 6};
  double y3[] = {1.1, 3, 17, 35, 35};
  cf::Dataset<double> d3(5, x3, y3);
  cf::ExpEquation expFit = d3.ExpFit();
  std::cout << expFit << std::endl;
}