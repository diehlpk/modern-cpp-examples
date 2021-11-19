#include <hpx/hpx_main.hpp>   
#include <hpx/include/lcos.hpp>
#include <cmath>
#include <iostream>

double taylor_part(double x, size_t start, size_t end){
    
    double result = 0; 
    for(size_t i = start; i < end; i++)
    {
        result += std::pow(-1,i+1)/i * std::pow(x-1,i);
    }
    return result;
}

// Can only use co_await inside a function that returns a future
hpx::future<double> get_taylor_part(double x, size_t n, size_t partitions) {
    double result = 0;
    std::vector<hpx::future<double>> futures;
    
    // Launch the function async
    futures.push_back(hpx::async(taylor_part,x,1,n/3));
    for(size_t i = 1; i < partitions; i++)
      futures.push_back(hpx::async(taylor_part,x,i*n/3,(i+1)*n/3));

    // Gather the results
    auto futures2 = co_await hpx::when_all(futures);

    // Sum the results
    for(size_t i=0; i < futures2.size(); i++)
        result += co_await futures2[i];

    co_return result;
}

int main(void){
    double x = 0.5;
    size_t n = 100;
    size_t partitions = 3;
    std::cout << get_taylor_part(x,n,partitions).get() << std::endl;
    return EXIT_SUCCESS;
}
