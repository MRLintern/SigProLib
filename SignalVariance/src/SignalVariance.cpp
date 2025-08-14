// implement SignalVariance functions

#include <cmath>
#include <numeric>
#include <stdexcept>
#include "SignalVariance.hpp"

// function to calculate the variance of the signals amplitude (components)
void SignalVariance(const double *signal_src_arr, std::uint32_t blockSize, double &result) {

	// ERROR checking
	if (!signal_src_arr || blockSize <= 1) {

		result = 0.0;

		return;
	}

	// calculate sum of amplitude components
	double amplitudeSum { std::accumulate(signal_src_arr, signal_src_arr + blockSize, 0.0) };

	// now calculate mean value of amplitude
	double meanAmplitude { amplitudeSum / static_cast<double>(blockSize) };

	// calculate sum of squared differences
	double sum_of_squares {0.0};

	for (std::uint32_t i {0}; i < blockSize; ++i) {

		double difference { signal_src_arr[i] - meanAmplitude };

		sum_of_squares += difference * difference;
	}

	// sample variance
	result = sum_of_squares / static_cast<double>(blockSize - 1);
}

// -- Optional -- //

// function overloading; signal stored in a vector
double SignalVariance(const std::vector<double>& signal) {

	if (signal.size() <= 1) { return 0.0; }

	// sum of amplitude components;
	double amplitudeSum { std::accumulate(signal.begin(), signal.end(), 0.0) };

	// now calculate mean value of amplitude
	double meanAmplitude { amplitudeSum / static_cast<double>(signal.size()) };

	// -- calculating sum of squared differences

	double sum_of_squares {0.0};

	for (double value : signal) {

		double difference { value - meanAmplitude };

		sum_of_squares += difference * difference;
	}

	return sum_of_squares / static_cast<double>(signal.size() - 1);
}
