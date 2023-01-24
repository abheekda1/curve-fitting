#include "matrix.hpp"

namespace cf {
template <class T> T matrix<T>::getDeterminant() {
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
    matrix<T> subMatrix(rows - 1, columns - 1);
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

template class matrix<int>;
template class matrix<long>;
template class matrix<long long>;

template class matrix<unsigned int>;
template class matrix<unsigned long>;
template class matrix<unsigned long long>;

template class matrix<float>;
template class matrix<double>;
} // namespace cf