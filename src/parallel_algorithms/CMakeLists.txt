# This file is part of Moden C++ exmaples 
# (https://github.com/diehlpk/modern-cpp-examples)
# Copyright (c) 2021 Patrick Diehl
# 
#  This program is free software: you can redistribute it and/or modify  
#  it under the terms of the GNU General Public License as published by  
#  the Free Software Foundation, version 3.
#
#  This program is distributed in the hope that it will be useful, but 
#  WITHOUT ANY WARRANTY; without even the implied warranty of 
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
#  General Public License for more details.
#
#  You should have received a copy of the GNU General Public License 
#  along with this program. If not, see <http://www.gnu.org/licenses/>.

add_executable(accumulate main_accumulate.cpp)


add_executable(accumulate_par main_accumulate_parallel.cpp)
target_link_options(accumulate_par PRIVATE -ltbb)
target_compile_options(accumulate_par PRIVATE -std=c++1z)

add_executable(for_openmp main_openmp.cpp)
target_link_options(for_openmp PRIVATE -fopenmp)
target_compile_options(for_openmp PRIVATE -fopenmp)

add_executable(for_parallel main_for_each.cpp)
target_link_options(for_parallel PRIVATE -ltbb)
target_compile_options(for_parallel PRIVATE -std=c++1z)
