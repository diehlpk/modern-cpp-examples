#include <cmath>
#include <future>
#include <iostream>

double taylor_part(double x, size_t start, size_t end){
    
    double result = 0; 
    for(size_t i = start; i < end; i++)
    {
        result += std::pow(-1,i+1)/i * std::pow(x-1,i);
    }
    return result;
}

int main(void){

    double x = 0.5;
    size_t n = 100;

    // Launch the function async
    std::future<double> f1 = std::async(taylor_part,x,1,n/2);
    std::future<double> f2 = std::async(taylor_part,x,n/2,n);

    // Gather the result
    std::cout << f1.get() + f2.get() << std::endl;
    return EXIT_SUCCESS;
}
