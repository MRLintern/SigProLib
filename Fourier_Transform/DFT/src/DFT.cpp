// DFT.cpp

#include <cmath>
#include <vector>
#include <complex>
#include "DFT.hpp"

// allocate bins with 0's
DFT::DFT(std::size_t length) : length_(length), bins_(length, std::complex<double>(0.0, 0.0)) {}

// -- calculate the magnitude of half of the frequency bins -- //

std::vector<double> DFT::HalfMagnitude() const {

	// real input; Note: signal composition; complex numbers so working with half the signal components
	std::size_t halfSignal { length_ / 2 }; // N/2 bins

	// magnitude
	std::vector<double> SignalMagnitude(halfSignal);

	for (std::size_t i {0}; i < halfSignal; ++i) {

		// complex number magnitude
		SignalMagnitude[i] = std::abs(bins_[i]);
	}

	return SignalMagnitude;
}

// compute the IDFT algorithm
std::vector<double> DFT::ComputeIDFT() const {

	// The IDFT is given by: x[n] = (1/N) * sum_{k = 0}^{N - 1} X[k] * exp(2*pi*j*k*n/N). Note: j = sqrt(-1)
	std::vector<double> output(length_, 0.0);

	// PI; used in exp(2*pi*j*k*n/N)
	const double TWO_PI { 2.0 * M_PI };

	for (std::size_t n {0}; n < length_; ++n) {

		// accumulation: sum of contributions of terms
		std::complex<double> acc {0.0};

		for (std::size_t k {0}; k < length_; ++k) {

			// angle to be rotated
			double angle { TWO_PI * static_cast<double>(k) * static_cast<double>(n) / static_cast<double>(length_) };

			// angle rotated in the complex plane via Eulers formula; note: angle = exp(+2*pi*j*k*n/N)
			std::complex<double> rotate(std::cos(angle), std::sin(angle));

			// sum up the rotated input components
			acc += bins_[k] * rotate;
		}

		// summing the complex result, now take the real part of signal expression
		output[n] = acc.real() / static_cast<double>(length_);
	}

	return output;
}

