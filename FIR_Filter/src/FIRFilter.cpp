// FIRFilter.cpp

/*

* Implement the Finite Impulse Responnse (FIR) Filter

* Key points:

	- An FIR filter output y[n] is the weighted sum of input samples x[n - k] 

	  by the coefficients h[k] (impulse response): y[n] = sum_k h[k] * x[n - k].

	- We compute a linear convolution and keep the output length equal to the input length

	  using index clamping - edge handling.

*/

#include <algorithm>
#include <stdexcept>
#include "FIRFilter.hpp"

// apply coefficients to filter
FIRFilter::FIRFilter(std::vector<double> coeffs) : h_{std::move(coeffs)}
{
	// make sure theres at least 1 coefficient
	if (h_.empty()) {

		throw std::invalid_argument("FIRFilter: coefficient vector can't be empty.");
	}
}

// apply moving average
void FIRFilter::applyFilter(const std::vector<double>& input, std::vector<double>& output) const {

	// number of input samples
	const std::size_t N = input.size();

	// number of coefficients
	const std::size_t M = h_.size();

	// resize and zero-initialise
	output.assign(N, 0.0);

	// for each output sample y[n], do the convolution sum:
	// y[n] = sum_{k = 0...M - 1} h[k] * x[n - k]
	// index clamping at boundaries so we never read out-of-range

	for (std::size_t n {0}; n < N; ++n) {

		// accumulator for y[n]
		double accumulate {0.0};

		// for each coefficient h[k], multiply with a corresponding x[n - k]

		for (std::size_t k{0}; k < M; ++k) {

			// compute input index we need
			// Note: careful with underflow: n and k are size_t

			const long idx = static_cast<long>(n) - static_cast<long>(k); 

			// clamp to valid input range [0, N - 1]
			const std::size_t xIndex { (idx < 0) ? 0u : (idx >= static_cast<long>(N) ? (N - 1) : static_cast<std::size_t>(idx)) };

			accumulate += h_[k] * input[xIndex];
		}

		output[n] = accumulate;
	}
}



	