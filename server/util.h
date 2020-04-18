#include <stdexcept>
#include <vector>

int randomNumberFromInterval(int intervalStart, int intervalEnd);

template <class T>
T randomElement(const std::vector<T> v);

template <class T>
std::vector<int> weightedDistribution(std::vector<int> probabilityPairs);
