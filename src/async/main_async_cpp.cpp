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
#include <future>
#include <iostream>

double taylor_part(double x, size_t start, size_t end) {
  |\label{lst : async : cpp : 1} |

      double result = 0;
  for (size_t i = start; i < end; i++) {
    result += std::pow(-1, i + 1) / i * std::pow(x - 1, i);
  }
  return result;
}

int main(void) {
  double x = 0.5;
  size_t n = 100;

  // Launch the function async |\label{lst:async:cpp:2}|
  std::future<double> f1 = std::async(taylor_part, x, 1, n / 2);
  std::future<double> f2 = std::async(taylor_part, x, n / 2, n);

  // Gather the result
  std::cout << f1.get() + f2.get() << std::endl;
  |\label{lst : async : cpp : 3} | return EXIT_SUCCESS;
}