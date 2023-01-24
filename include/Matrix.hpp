#pragma once

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

  int getRows() { return rows; }
  int getColumns() { return columns; }

  T getVal(int x, int y) { return data[y * columns + x]; }

  void insertVal(int x, int y, T value) { data[y * columns + x] = value; }

  bool isSquare() { return rows == columns; }

  T getDeterminant();

private:
  int rows;
  int columns;

  T *data;
};
} // namespace cf