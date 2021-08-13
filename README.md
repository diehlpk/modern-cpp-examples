# Supplementary material: ADVANCED PARALLEL PROGRAMMING IN C++

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/1c51042683ed4bcdb06cea617118e7be)](https://www.codacy.com/gh/diehlpk/SIAM-Review-examples/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=diehlpk/SIAM-Review-examples&amp;utm_campaign=Badge_Grade) [![CircleCI](https://circleci.com/gh/diehlpk/SIAM-Review-examples.svg?style=shield)](https://circleci.com/gh/diehlpk/SIAM-Review-examples)

The build system [CMake](https://cmake.org/) is used to compile all the examples. 

The following code snippet shows how to compile the examples with the parallel algorithms and OpenMP

```bash
mkdir build
cd build
cmake ..
make
```

## Dependencies

* Thread Building Blocks ([TBB](https://github.com/oneapi-src/oneTBB)) for the parallel algorithms
* GNU compiler collection (gcc) >= 9 to support the parallel algorithms

Note that we provide a [Docker image](https://hub.docker.com/repository/registry-1.docker.io/diehlpk/siam-review-base/tags?page=1&ordering=last_updated) with all the dependencies installed and Docker image with all examples compiled 
