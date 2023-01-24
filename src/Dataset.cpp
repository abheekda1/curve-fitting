#include "Dataset.hpp"

namespace cf {
template <class T> std::vector<double> Dataset<T>::PolyFit(int order) {
  return std::vector<double>();
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
