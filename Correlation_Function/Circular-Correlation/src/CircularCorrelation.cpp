// CircularCorrelation.cpp

#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

#include "CircularCorrelation.hpp"

CircularCorrelation::CircularCorrelation(std::shared_ptr<std::vector<double>> x, std::shared_ptr<std::vector<double>> y)

	: x_(std::move(x)), y_(std::move(y))
 
{
	// -- safety checks: arguments -- //

	if (!x_ || !y_) {

		throw std::invalid_argument("Null-Pointer passed for Signals.");
	}


	if (x_->empty() || y_->empty()) {

		throw std::invalid_argument("Signal Lengths aren't the Same Size.");
	}

	if (x_->size() != y_->size()) {

		throw std::invalid_argument("ERROR: Signal Lengths are not the same!");
	}

	result_.resize(x_->size(), 0.0);
}

// compute the circular correlation
void CircularCorrelation::Compute() {

	// -- safety checks: runtime errors -- //
	if (!x_ || !y_) {

		throw std::runtime_error("Null Signal Pointer");
	}

	const std::size_t N = x_->size();

	if (N == 0) {

		throw std::runtime_error("Empty Signals.");
	}

	// computation/algorithm for calculating circular correlation
	for (std::size_t m {0}; m < N; ++m) {

		double sum { 0.0 };

		// wrap around using modulo for circular shift
		for (std::size_t n {0}; n < N; ++n) {

			std::size_t index = (n + m) % N;

			sum += (*x_)[n] * (*y_)[index];
		}

		result_[m] = sum;
	}
}

// normalise the correlation result
void CircularCorrelation::Normalise() {

	// max. absolute value; scales result between [-1, 1]
	double max_value { 0.0 };

	for (const auto& value : result_) {

		max_value = std::max(max_value, std::abs(value));
	}

	if (max_value > 0.0) {

		for (auto& value : result_) {

			value /= max_value;
		}
	}
}

// get the result of the calculated correlation value
const std::vector<double>& CircularCorrelation::GetResult() const {

	return result_;
}


