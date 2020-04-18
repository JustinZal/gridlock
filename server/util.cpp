#include <util.h>
#include <iostream>
#include <random>
#include <vector>

int randomNumberFromInterval(int start = 0, int end = 0) {
  assert((end >= start));

  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_int_distribution<> distr(start, end);

  return distr(eng);
}

template <class T>
T randomElement(const std::vector<T> v) {
  const auto length = v.size();
  assert(length > 0);
  return v[randomNumberFromInterval(0, length - 1)];
}
