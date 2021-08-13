#include <cmath>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
#include <execution>

int main(void) {
  size_t n = 10000;
  // Generate the vector with the length
  std::vector<double> v = std::vector<double>(n);
  // Initilaize the vector with -1
  std::generate(v.begin(), v.end(), std::rand);
  // Fill a new vector contaning the indicies
  std::vector<size_t> i = std::vector<size_t>(n);
  std::iota(std::begin(i), std::end(i), 0);

  std::for_each(std::execution::par, i.begin(), i.end(),
                [&](auto&& item) { v[item] = std::sqrt(v[item]); });

  return EXIT_SUCCESS;
}
