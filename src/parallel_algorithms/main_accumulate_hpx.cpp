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
#include <hpx/include/parallel_reduce.hpp>
#include <hpx/parallel/algorithms/fill.hpp>

#include <iostream>
#include <vector>
#include <numeric>

int main(void) {
  size_t n = 10000;
  // Generate the vector with the length
  std::vector<int> v(n);
  // Initilaize the vector with -1
  hpx::fill(hpx::execution::par, v.begin(), v.end(), -1);
  // Compute the sum of all elements

  hpx::future<double> f = hpx::ranges::reduce(
      hpx::execution::par(hpx::execution::task), v.begin(), v.end(), 0.0);
  // Output the result
  std::cout << "Result= " << f.get() << std::endl;

  return EXIT_SUCCESS;
}
