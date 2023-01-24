#include <vector>

#include "Dataset.hpp"
#include "Matrix.hpp"

namespace cf {
template <class T> std::vector<double> Dataset<T>::PolyFit(int order) {
  std::vector<double> ret(order + 1);

  Matrix<T> M(order + 1, order + 1);
  for (int i = 0; i <= order; i++) {
    for (int j = 0; j <= order; j++) {
      M.insertVal(i, j, 0);
      for (int k = 0; k < N; k++) {
        M.insertVal(i, j, M.getVal(i, j) + pow(x[k], i + j));
      }
    }
  }

  std::vector<double> b(order + 1);

  for (int i = 0; i <= order; i++) {
    b.at(i) = 0;
    for (int j = 0; j < N; j++) {
      b.at(i) += pow(x[j], i) * y[j];
    }
  }

  for (int i = 0; i <= order; i++) {
    T *MiData = new T[M.getRows() * M.getColumns()];
    std::copy(M.getData(), M.getData() + (M.getColumns() * M.getRows()),
              MiData);
    Matrix<T> Mi(order + 1, order + 1, MiData);
    for (int j = 0; j <= order; j++) {
      Mi.insertVal(i, j, b.at(j));
    }

    ret[i] = Mi.getDeterminant() / M.getDeterminant();
  }

  return ret;
}
template <class T> std::pair<double, double> Dataset<T>::LogFit(double base) {
  return std::pair<double, double>();
}

template class Dataset<int>;
template class Dataset<long>;
template class Dataset<long long>;

template class Dataset<unsigned int>;
template class Dataset<unsigned long>;
template class Dataset<unsigned long long>;

template class Dataset<float>;
template class Dataset<double>;
} // namespace cf
