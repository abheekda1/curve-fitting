#pragma once

#include <utility>

namespace cf {

template <class T> class matrix {
public:
  matrix(int rows, int columns) : rows(rows), columns(columns) {
    data = new T[columns * rows];
  }

  int getRows() { return rows; }
  int getColumns() { return columns; }

  T getVal(std::pair<int, int> position) {
    return data[position.second * columns + position.first];
  }

  void insertVal(std::pair<int, int> position, T value) {
    data[position.second * columns + position.first] = value;
  }

private:
  int rows;
  int columns;

  T *data;
};

} // namespace cf