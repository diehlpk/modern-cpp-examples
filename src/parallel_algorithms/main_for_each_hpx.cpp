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

#include <hpx/hpx_main.hpp>
#include <hpx/include/parallel_for_loop.hpp>

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

  hpx::for_loop(hpx::execution::par, 0, v.size(),
                [&](boost::uint64_t i) { v[i] = std::sqrt(v[i]); });

  return EXIT_SUCCESS;
}
