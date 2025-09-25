// DFT.hpp

#pragma once

#include <vector>
#include <cmath>
#include <complex>
#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include "constants.hpp"

class DFT {

private:

	// length of signal
	std::size_t length_{};

	// frequency bins
	std::vector<std::complex<double>> bins_{};

public:

	// allocate space for N bins; default is SIG_LENGTH
	explicit DFT(std::size_t length = SIG_LENGTH);

	// compute DFT; templated to allow for any container type (array or vector) 
	template <typename Container>

	void ComputeDFT(const Container& input);

	// compute magnitude of half the frequency bins
	std::vector<double> HalfMagnitude() const;

	// compute the inverse discrete fourier transform (IDFT)
	std::vector<double> ComputeIDFT() const;

	// functions for accessing frequency bins and signal length values
	const std::vector<std::complex<double>>& bins() const noexcept { return bins_; }
	std::size_t length() const noexcept { return length_; }
};

// -- DFT algorithm implemented via a template -- //

template <typename Container>

void DFT::ComputeDFT(const Container& input) {

	if (input.size() != length_) {

		throw std::invalid_argument("ISSUE: The Size of the Input File != to its Length");
	}

	// PI; used in exp(-2*pi*j*k*n/N) (*)
	const double TWO_PI { 2.0 * M_PI };

	// reset bins
	std::fill(bins_.begin(), bins_.end(), std::complex<double>(0.0, 0.0));

	// DFT algorithm: X[k] = sum_{n = 0}^{N - 1} x[n] * exp(-2*pi*j*k*n/N). Note: j = sqrt(-1)
	for (std::size_t k {0}; k < length_; ++k) {

		// accumulation: sum of contributions of terms
		std::complex<double> acc {0.0};

		for (std::size_t n {0}; n < length_; ++n) {

			// angle: see above for the exp argument (*); this is expanded via Euler's formula: exp(angle) = cos(angle) - j*sin(angle)
			double angle { TWO_PI * static_cast<double>(k) * static_cast<double>(n) / static_cast<double>(length_) };

			// rotate angle (in the complex plane):
			std::complex<double> rotate(std::cos(angle), -std::sin(angle));

			// sum up the rotated input components
			acc += input[n] * rotate;
		}

		// assign all the contributions calculated above to half the frequency bins
		bins_[k] = acc;
	}
}
