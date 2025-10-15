// CircularCorrelation.hpp

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

// class to compute circular correlation between a time-domain signal and one that has been time-shifted
// these signals are periodic

// equation/formula: Rxy[m] = SUM{n = 0}^{N - 1} x[n] * y[(n + m) mod N]; see README.md for more information

class CircularCorrelation {

private:

	// first time-domain signal
	std::shared_ptr<std::vector<double>> x_;

	// time-domain shifted signal
	std::shared_ptr<std::vector<double>> y_;

	// correlation result
	std::vector<double> result_;

public:

	// x (1st signal) pointer
	// y (2nd signal) pointer

	CircularCorrelation(std::shared_ptr<std::vector<double>> x, std::shared_ptr<std::vector<double>> y);

	// function to calculate correlation
	void Compute();

	// function to get the calculated correlation result
	const std::vector<double>& GetResult() const;

	// as per standard DSP, normalise the result on the range [-1, 1]
	void Normalise();
};