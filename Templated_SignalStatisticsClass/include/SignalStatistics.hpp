// templated statistics class
// 1 class to calculate mean, variance and standard deviation

#pragma once

#include <vector>
#include <cstddef>
#include <type_traits>
#include <numeric>
#include <cmath>
#include <stdexcept>

// type T must be an arithmetic type; i.e. int, float, double, etc
template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class SignalStatistics {

private:

	// for storing signal (amplitude) components
	std::vector<T> signal;

public:

	// constructor from pointer + length
	SignalStatistics(const T* signal_src_arr, std::size_t signal_length) {

		// check: any problems with signal file..?
		if (!signal_src_arr || signal_length == 0) {

			throw std::invalid_argument("Signal data is rubbish or empty.");
		}

		// add amplitude components to signal vector/container
		signal.assign(signal_src_arr, signal_src_arr + signal_length);
	}

	// constructor from vector
	explicit SignalStatistics(std::vector<T> signal_) 

		: signal(std::move(signal_)) {

			// check: is the signal empty..?
			if (signal.empty()) {

				throw std::invalid_argument("No Signal data.");
			}
	}

	// -- Functions for calculating signal statistics -- // 

	// Mean amplitude statistic
	T SignalMean() const {

		// add up amplitude components
		T sum = std::accumulate(signal.begin(), signal.end(), T(0));

		// return the mean amplitude value
		return sum / static_cast<T>(signal.size());
	}

	// variance of amplitude components
	T SignalVariance() const {

		if (signal.size() <= 1) { return T(0); }

		// calculate mean value; call SignalMean()
		T mean  { SignalMean() };

		// sum of squares
		T square_sum = T(0);

		// now find square sum of differences
		for (T val : signal) {

			T difference = val - mean;

			square_sum += difference * difference;
		}

		// return the variance
		return square_sum / static_cast<T>(signal.size() - 1);
	}

	// standard deviation of amplitude components; sqrt(variance)
	T SignalSTDDev() const {

		return static_cast<T>(std::sqrt(static_cast<long double>(SignalVariance())));
	}

	// -- EOF -- // 
};
