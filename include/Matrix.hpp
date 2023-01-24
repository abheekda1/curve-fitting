#pragma once

#include <stdexcept>
#include <utility>

namespace cf {

// works with number types
template <class T> class Matrix {
public:
  Matrix(int rows, int columns) : rows(rows), columns(columns) {
    data = new T[columns * rows];
  }

  Matrix(int rows, int columns, T data[])
      : rows(rows), columns(columns), data(data) {}

  int getRows() { return rows; }
  int getColumns() { return columns; }

  T getVal(std::pair<int, int> position) {
    return data[position.second * columns + position.first];
  }

  void insertVal(std::pair<int, int> position, T value) {
    data[position.second * columns + position.first] = value;
  }

  bool isSquare() { return rows == columns; }

  T getDeterminant();

private:
  int rows;
  int columns;

  T *data;
};
} // namespace cf