add_executable(accumulate main_accumulate.cpp)


add_executable(accumulate_par main_accumulate_parallel.cpp)
target_link_options(accumulate_par PRIVATE -ltbb)
target_compile_options(accumulate_par PRIVATE -std=c++1z)

add_executable(for_openmp main_openmp.cpp)
target_link_options(for_openmp PRIVATE -fopenmp)
target_compile_options(for_openmp PRIVATE -fopenmp)
