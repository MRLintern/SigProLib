// Correlation.cpp

#include <vector>
#include <cmath>
#include <memory>
#include <cstddef>

#include "Correlation.hpp"
#include "Signal.hpp"


// -- auto-correlation algorithm -- //

// * formula: Rxx(lag) = sum_{n = 0}^{N - lag - 1} x{n} * x[n + lag]

// Note: for the details on normalising the auto-correlation algorithm see Correlation.hpp

// compute Rxx(0), the energy of signal x[n]
static double SignalEnergy(const std::vector<double>& x) {

	double energy {0.0};

	for (auto val : x) {

		energy += val * val;
	}

	return energy;
}

// auto-correlation algorithm with normalisation
std::unique_ptr<std::vector<double>> Correlation::AutoCorrelation(const Signal& signal, bool normalise) {

	// 
	const auto& x = signal.GetSamples();

	// size of sample lags
	std::size_t N = x.size();

	// vector for holding the N lags; these run from 0 to N - 1
	auto result = std::make_unique<std::vector<double>>(N, 0.0);

	// lags for outer region
	for (std::size_t lag {0}; lag < N; ++lag) {

		double sum {0.0};

		// lags for inner region
		for (std::size_t n {0}; n < N - lag; ++n) {

			sum += x[n] * x[n + lag]; 
		}

		(*result)[lag] = sum;
	}

	// normalised by Rxx(0)
	if (normalise && (*result)[0] != 0.0) {

		double r0 = (*result)[0];

		for (auto& val : *result) {

			val /= r0;
		}
	}

	return result;
}

// -- cross-correlation -- //

// * formula: Rxy(lag) = sum_{n = 0}^{N - lag - 1} x[n] * y[n + lag]

// cross-correlation algorithm
std::unique_ptr<std::vector<double>> Correlation::CrossCorrelation(const Signal& xSignal, const Signal& ySignal, bool normalise) {

	//
	const auto& x = xSignal.GetSamples();

	//
	const auto& y = ySignal.GetSamples();

	// size of sample lags
	std::size_t N = x.size();

	// vector for holding the N lags; these run from 0 to N - 1
	auto result = std::make_unique<std::vector<double>>(N, 0.0);

	// lags for y direction
	for (std::size_t lag {0}; lag < N; ++lag) {

		double sum {0.0};

		// lags for x direction
		for (std::size_t n {0}; n < N - lag; ++n) {

			sum += x[n] * y[n + lag];
		}

		(*result)[lag] = sum;
	}

	// normalise using sqrt{Rxx(0) X Ryy(0)}
	if (normalise) {

		double normaliseFactor = std::sqrt(SignalEnergy(x) * SignalEnergy(y));

		if (normaliseFactor != 0.0) {

			for (auto& val : *result) {

				val /= normaliseFactor;
			}
		}
	}

	return result;
}




