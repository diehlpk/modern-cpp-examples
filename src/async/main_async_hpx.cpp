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
#include <hpx/include/lcos.hpp>
#include <cmath>
#include <iostream>

double taylor_part(double x, size_t start, size_t end) {
  double result = 0;
  for (size_t i = start; i < end; i++) {
    result += std::pow(-1, i + 1) / i * std::pow(x - 1, i);
  }
  return result;
}

int main(void) {
  double x = 0.5;
  size_t n = 100;
  size_t partitions = 3;
  std::vector<hpx::future<double>> futures;

  // Launch the function async
  futures.push_back(hpx::async(taylor_part, x, 1, n / 3));
  for (size_t i = 1; i < partitions; i++)
    futures.push_back(hpx::async(taylor_part, x, i * n / 3, (i + 1) * n / 3));

  // Gather the result
  hpx::when_all(futures).then([](auto&& f) {
    std::vector<hpx::future<double>> futures = f.get();
    double result = 0;
    for (size_t i = 0; i < futures.size(); i++) result += futures[i].get();
    std::cout << result << std::endl;
  });
  return EXIT_SUCCESS;
}
