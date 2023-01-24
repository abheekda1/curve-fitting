#pragma once

namespace cf {
template <class T> class Dataset {
public:
  Dataset(int N, T x[], T y[]) : N(N), x(x), y(y){};
  Dataset(int N) : N(N), x(new T[N]), y(new T[N]){};

private:
  int N; // number of points
  T *x;  // array of x-values
  T *y;  // array of y-values
};
} // namespace cf