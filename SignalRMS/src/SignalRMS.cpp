// implement SignalRMS

#include <cmath>
#include <cstdint>
#include "SignalRMS.hpp"

// function for calculating the RMS of the signal
void SignalRMS(const double *signal_src_arr, std::uint32_t blockSize, double *result) {

	// error checking: can't divide by 0
	if (blockSize == 0 || signal_src_arr == nullptr || result == nullptr) {

		if (result) { *result = 0.0; }

		return;
	}

	double sum_of_squares {0.0};

	// loop through all samples
	for (std::uint32_t i {0}; i < blockSize; ++i) {

		double sample { signal_src_arr[i] };

		// square and accumulate
		sum_of_squares += sample * sample;
	}

	// RMS = sqrt(sum(sample^2) / N)
	*result = std::sqrt(sum_of_squares / static_cast<double>(blockSize));
}
