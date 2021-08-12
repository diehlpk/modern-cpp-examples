# Supplementary material: ADVANCED PARALLEL PROGRAMMING IN C++

The build system [CMake](https://cmake.org/) is used to compile all the exmaples. 

The following code snippet shows how to compile the examples with the parallel algorithms and OpenMP

```bash
mkdir build
cd build
cmake ..
make
```

## Dependencies

* Thread Building Blocks ([TBB](https://github.com/oneapi-src/oneTBB)) for the parallel algorthms
* GNU compiler collection (gcc) >= 9 to support the parallel algorithms

Note that we provide a docker image with all the depencies installed and all the examples compiled. 
