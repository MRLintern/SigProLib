// MovingAverageFilter.cpp

// implement MovingAverageFilter

#include <numeric>
#include <algorithm> // Note: makes use of std::clamp for clamping indices on boundaries
#include "MovingAverageFilter.hpp"

// initialise to set filter window size
MovingAverageFilter::MovingAverageFilter(std::size_t windowSize) : windowSize_{ windowSize }
{
	// odd window size required
	if (windowSize_ < 3 || (windowSize_ % 2 == 0)) {

		throw std::invalid_argument("MovingAverageFilter Window Size Must be Odd and >= 3");
	}
} 

// apply moving average filter function
void MovingAverageFilter::applyFilter(const std::vector<double>& input, std::vector<double>& output) const {

	const std::size_t N = input.size();

	output.resize(N);

	// half window size; 11 -> 5 on each side
	const std::size_t half { windowSize_/2 };

	// for each output position i, average input[j] for j in [i - half, i + half]
	// with boundary handling by clamping indices into [0, N - 1]

	for (std::size_t i {0}; i < N; ++i) {

		const std::size_t left { (i > half) ? (i - half) : 0 };
		const std::size_t right { std::min(N - 1, i + half) };

		// accumulate the window sum
		double sum {0.0};

		for (std::size_t j {left}; j <= right; ++j) {

			sum += input[j];
		}

		// divide by actual count in window (fixed = windowSize_ when not near edge)
		const std::size_t count { right - left + 1 };

		output[i] = sum/static_cast<double>(count); // where is count declared in the project?
	}
}