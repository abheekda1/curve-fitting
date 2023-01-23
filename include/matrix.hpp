#pragma once

#include <utility>

namespace cf {
template <class T> class matrix {
public:
  matrix(int rows, int columns) : rows(rows), columns(columns) {
    data = new T[columns * rows];
  }

  matrix(int rows, int columns, T data[]) : rows(rows), columns(columns), data(data) {}

  int getRows() { return rows; }
  int getColumns() { return columns; }

  T getVal(std::pair<int, int> position) {
    return data[position.second * columns + position.first];
  }

  void insertVal(std::pair<int, int> position, T value) {
    data[position.second * columns + position.first] = value;
  }

  bool isSquare() { return rows == columns; }

  int getDeterminant() {
    if (!isSquare()) throw std::runtime_error("cannot get determinant of a non-square matrix");

    if (rows == 2) {
      return (this->getVal(std::make_pair(0, 0)) * this->getVal(std::make_pair(1, 1)))
            - (this->getVal(std::make_pair(0, 1)) * this->getVal(std::make_pair(1, 0)));
    }

    int ret = 0;

    for (int i = 0; i < columns; i++) {
        matrix<T> subMatrix(rows - 1, columns - 1);
        int currentColumn = 0;
        for (int j = 0; j < columns; j++) {
            if (j == i) continue;
            int currentRow = 0;
            for (int k = 1; k < rows; k++) {
                subMatrix.insertVal(std::make_pair(currentColumn, currentRow), this->getVal(std::make_pair(j, k)));
                currentRow++;
            }
            currentColumn++;
        }
        ret += (this->getVal(std::make_pair(i, 0)) * (subMatrix.getDeterminant() * (i % 2 == 0 ? 1 : -1)));
    }

    return ret;
  }

private:
  int rows;
  int columns;

  T *data;
};
} // namespace cf