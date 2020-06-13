#include "util.hpp"
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

template <class T>
T weightedDistribution(std::vector<T, int> probabilityPairs) {
  const auto length = probabilityPairs.size();
  std::vector<T> events;

  for (int i = 0; i < probabilityPairs.size(); i++) {
    for (int j = 0; j < probabilityPairs[i][1]; j++) {
      events.push_back(probabilityPairs[i][0]);
    };
  };

  return randomElement(events);
}

std::string exec(const char* cmd){
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
