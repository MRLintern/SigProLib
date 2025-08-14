
// SignalSTDDev.cpp

#include <cmath>
#include <cstdint>
#include <numeric>
#include <stdexcept>
#include "SignalSTDDev.hpp"

// -- Calculate the Mean amplitude of signal -- //

// function to calculate the average amplitude of the signal
void SignalMean(const double *signal_src_arr, std::uint32_t blockSize, double *result) {

	if (!signal_src_arr || blockSize == 0 || !result) {

		throw std::invalid_argument("Invalid arguments passed");
	}

	// std::accumulate is used to sum up all the components of amplitude in the array
	double amplitudeSum { std::accumulate(signal_src_arr, signal_src_arr + blockSize, 0.0) };

	// calculate the mean value
	*result = amplitudeSum / static_cast<double>(blockSize);
}

// -- Calculate Variance statistic of signal Amplitude -- //

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


// -- End of optional SignalVariance function for loading signal stored in a vector -- //

// -- Calculate Standard Deviation statistic of signal Amplitude -- //

// function for calculating the standard deviation of the input signal
void SignalSTDDev(const double *signal_src_arr, std::uint32_t blockSize, double &result) {

	double amplitudeVariance {0.0};

	// call function for calculating variance statistic
	SignalVariance(signal_src_arr, blockSize, amplitudeVariance);

	// standard deviation statistic is the square-root of variance
	result = std::sqrt(amplitudeVariance);
}

// optional: overload SignalSTDDev function -- //

// overload SignalSTDDev function if the signal is store in a vector
double SignalSTDDev(const std::vector<double>& signal) {

	double amplitudeVariance { SignalVariance(signal) };

	return std::sqrt(amplitudeVariance);
}

// end of optional overload SignalSTDDev function -- //

