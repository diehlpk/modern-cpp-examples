/*
  This file is part of Moden C++ exmaples
  (https://github.com/diehlpk/modern-cpp-examples)
  Copyright (c) 2021 Patrick Diehl

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, version 3.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <cmath>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>

int main(void) {
  size_t n = 10000;
  // Generate the vector with the length
  std::vector<double> v = std::vector<double>(n);
  // Initilaize the vector with -1
  std::generate(v.begin(), v.end(), std::rand);

#pragma omp parallel for
  for (size_t i = 0; i < v.size(); i++) v[i] = std::sqrt(i);

  return EXIT_SUCCESS;
}
