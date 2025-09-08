// MovingAverageFilter.hpp


/*

- Finite Impulse Response (FIR) Moving Average Filter

- Uses a symmetric, odd-length window: e.g., 3, 5, 7, 11, ...

- Output length = input length

- Boundaries: clamp indices - replicate edge samples => every output sample is a true average over windowSize samples

*/

#pragma once

#include <vector>
#include <cstddef>
#include <stdexcept>
#include "IFilter.hpp"

class MovingAverageFilter : public IFilter {

private:

	std::size_t windowSize_ {};

public:

	explicit MovingAverageFilter(std::size_t windowSize);

	// rule of 5; compiler defaults
	~MovingAverageFilter() noexcept = default;
	MovingAverageFilter(const MovingAverageFilter&) = default;
	MovingAverageFilter(MovingAverageFilter&&) noexcept = default;
	MovingAverageFilter& operator=(const MovingAverageFilter&) = default;
	MovingAverageFilter& operator=(MovingAverageFilter&&) noexcept = default;

	void applyFilter(const std::vector<double>& input, std::vector<double>& output) const override;

	std::size_t window() const noexcept { return windowSize_; }

};