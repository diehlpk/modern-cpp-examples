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
