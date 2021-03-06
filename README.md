# Supplementary material: ADVANCED PARALLEL PROGRAMMING IN C++

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/1c51042683ed4bcdb06cea617118e7be)](https://www.codacy.com/gh/diehlpk/modern-cpp-examples/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=diehlpk/modern-cpp-examples&amp;utm_campaign=Badge_Grade) [![CircleCI](https://circleci.com/gh/diehlpk/modern-cpp-examples.svg?style=shield)](https://github.com/diehlpk/modern-cpp-examples)

The build system [CMake](https://cmake.org/) is used to compile all the examples. 

The following code snippet shows how to compile the examples with the parallel algorithms and OpenMP

```bash
mkdir build
cd build
cmake ..
make
```

The following code snippet show how to compile the optional HPX examples


```bash
mkdir build
cd build
cmake -DWITH_HPX=ON ..
make
```

## Dependencies

* Thread Building Blocks ([TBB](https://github.com/oneapi-src/oneTBB)) for the parallel algorithms
* GNU compiler collection (gcc) >= 9 to support the parallel algorithms
* Optional: The C++ Standard Library for Paralism and Concurrency ([HPX](https://github.com/STEllAR-GROUP/hpx)) 

Note that we provide a [Docker image](https://hub.docker.com/r/diehlpk/modern-cpp-base) with all the dependencies installed and Docker image with all examples compiled 
