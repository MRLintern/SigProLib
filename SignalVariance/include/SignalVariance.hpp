// SignalVariance.hpp

#include <cstdint>
#include <vector>

/*

* signal_src_arr: pointer to the start of the input signal

* blockSize: number elements (amplitude components) in the signal array

* result: reference to where the calculated variance value will be stored

*/

// function calculates the variance of the variance of the amplitude components
void SignalVariance(const double *signal_src_arr, std::uint32_t blockSize, double &result);

// overloading: if we store the signal in a vector (container) we can use this:
double SignalVariance(const std::vector<double>& signal);
