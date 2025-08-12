// implement the SignalMean function

#include <cstdint> // for std::uint32_t
#include <numeric> // for std::accumulate
#include "Mean.hpp"

// function to calculate the average amplitude of the signal
void SignalMean(const double *signal_src_arr, std::uint32_t blockSize, double *result) {

	// std::accumulate is used to sum up all the components of amplitude in the array
	double sum = std::accumulate(signal_src_arr, signal_src_arr + blockSize, 0.0);

	// calculate the mean value
	*result = sum / static_cast<double>(blockSize);
}
