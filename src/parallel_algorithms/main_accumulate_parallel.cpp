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
#include <iostream>
#include <vector>
#include <numeric>
#include <execution>

int main(void) {
  size_t n = 10000;
  // Generate the vector with the length
  std::vector<int> v = std::vector<int>(n);
  // Initilaize the vector with -1
  std::fill(std::execution::par, v.begin(), v.end(), -1);
  // Compute the sum of all elements
  int s = std::reduce(std::execution::par, v.begin(), v.end(), 0.0);
  // Output the result
  std::cout << "Result= " << s << std::endl;

  return EXIT_SUCCESS;
}