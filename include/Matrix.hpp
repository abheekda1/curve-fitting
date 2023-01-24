#pragma once

#include <iomanip>
#include <ostream>
#include <stdexcept>
#include <utility>

namespace cf {
// works with number types
template <class T> class Matrix {
public:
  Matrix(int rows, int columns)
      : rows(rows), columns(columns), data(new T[rows * columns]) {}

  Matrix(int rows, int columns, T data[])
      : rows(rows), columns(columns), data(data) {}

  int getRows() const { return rows; }
  int getColumns() const { return columns; }
  T *getData() { return data; }

  T getVal(int x, int y) const { return data[y * columns + x]; }

  void insertVal(int x, int y, T value) { data[y * columns + x] = value; }

  bool isSquare() { return rows == columns; }

  T getDeterminant();

  friend std::ostream &operator<<(std::ostream &os, const Matrix<T> &m) {
    for (int i = 0; i < m.getRows(); i++) {
      os << '[';
      for (int j = 0; j < m.getColumns(); j++) {
        os << std::setw(10) << m.getVal(j, i) << ' ';
      }
      os << "]\n";
    }
    return os;
  }

private:
  int rows;
  int columns;

  T *data;
};
} // namespace cf