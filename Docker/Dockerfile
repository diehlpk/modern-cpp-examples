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

From fedora:35
MAINTAINER Patrick Diehl <patrickdiehl1@gmail.com>

RUN dnf update -y
RUN dnf groupinstall "Development Tools" -y
RUN dnf install  gcc-c++ cmake git asio-devel boost-devel hwloc-devel gperftools-devel tbb-devel wget -y

RUN git clone --depth 1 -b fcoroutines-gcc https://github.com/msimberg/hpx.git  && cd hpx && wget https://patch-diff.githubusercontent.com/raw/STEllAR-GROUP/hpx/pull/5667.patch && git apply 5667.patch  && mkdir build && cd build && cmake -DHPX_CXX_STANDARD=20 -DHPX_HAVE_AWAIT=ON -DHPX_HAVE_CXX20_COROUTINES=ON .. && make -j 2 && make install

