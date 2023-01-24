#include "Matrix.hpp"

namespace cf {
template <class T> T Matrix<T>::getDeterminant() {
  if (!this->isSquare())
    throw std::runtime_error("cannot get determinant of a non-square matrix");

  if (rows == 2) {
    return (this->getVal(std::make_pair(0, 0)) *
            this->getVal(std::make_pair(1, 1))) -
           (this->getVal(std::make_pair(0, 1)) *
            this->getVal(std::make_pair(1, 0)));
  }

  T ret = 0;

  for (int i = 0; i < columns; i++) {
    Matrix<T> subMatrix(rows - 1, columns - 1);
    int currentColumn = 0;
    for (int j = 0; j < columns; j++) {
      if (j == i)
        continue;
      int currentRow = 0;
      for (int k = 1; k < rows; k++) {
        subMatrix.insertVal(std::make_pair(currentColumn, currentRow),
                            this->getVal(std::make_pair(j, k)));
        currentRow++;
      }
      currentColumn++;
    }
    ret += (this->getVal(std::make_pair(i, 0)) *
            (subMatrix.getDeterminant() * (i % 2 == 0 ? 1 : -1)));
  }

  return ret;
}

template class Matrix<int>;
template class Matrix<long>;
template class Matrix<long long>;

template class Matrix<unsigned int>;
template class Matrix<unsigned long>;
template class Matrix<unsigned long long>;

template class Matrix<float>;
template class Matrix<double>;
} // namespace cf