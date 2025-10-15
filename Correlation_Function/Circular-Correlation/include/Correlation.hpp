// Correlation.hpp

#pragma once

#include <vector>
#include <memory>
#include "Signal.hpp"

// -- Normalisation -- //

// * For both correlation algorithms, they will be normalised on the range [-1, 1]

// -- auto-correlation -- //

// * formula: autoCorrelationNormalised(t) = Rxx(t) / Rxx(0)
// * Rxx(t): unormalised cross-correlation at lag t
// * Rxx(0): energy of signal x 

// Correlation class provides functionality for the correlation algorithms

// -- cross-correlation -- //

// * formula: crossCorrelationNormalised(t) = Rxy(t) / sqrt{Rxx(0) X Ryy(0)}
// * this is used for 2 signals, x[n] and y[n]
// * argument: Rxy(t): unormalised cross-correlation at lag t for signals x[n] and y[n]
// * Rxx(0): energy of signal x
// * Ryy(0): energy of signal y

class Correlation {

public:

	// -- auto-correlation algorithm -- //

	// * argument: input signal
	// * argument: normalise; to ensure that the auto-correlation algorithm is applied between [-1, 1]
	// * returns a vector containing the auto-correlation sequences

	static std::unique_ptr<std::vector<double>> AutoCorrelation(const Signal& signal, bool normalise = false);

	// -- cross-correlation algorithm -- //

	// * argument: first signal xSig
	// * argument: second signal ySig
	// * argument: normalise; to ensure that the cross-correlation algorithm is applied between [-1, 1]
	// * returns a vector containing the cross-correlation sequences

	static std::unique_ptr<std::vector<double>> CrossCorrelation(const Signal& xSig, const Signal& ySig, bool normalise = false);
};