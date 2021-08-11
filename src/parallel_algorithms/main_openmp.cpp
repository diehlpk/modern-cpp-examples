#include <cmath>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>

int main(void){

    size_t n = 10000;
    // Generate the vector with the length
    std::vector<double> v = std::vector<double>(n);
    // Initilaize the vector with -1
    std::generate(v.begin(),v.end(),std::rand); 
    
    #pragma omp parallel
    #pragma omp for
    for (size_t i = 0 ; i < v.size(); i++)
        v[i] = std::sqrt(i);

    return EXIT_SUCCESS;

 }
