// FIRFilter.hpp

/*

- The Finite Impulse Responnse (FIR) Filter

- This is constructed with a coefficient vector (AKA impulse response); denoted by 'h'

- Performs (linear) convolution on input signal/data with impulse response 'h'.

- The input signal length is the same size as the input signal; i.e. the boundaries are clampled by replicating the edges

- Note: the FIRFilter class is separate from the MovingAverageFilter class. Although the Moving Average method is essentially a special case of FIRFilter

*/

#pragma once

#include <vector>
#include <cstddef>
#include "IFilter.hpp"

// generic FIR filter
class FIRFilter : public IFilter {

private:

	// coefficient vector (AKA impulse response)
	std::vector<double> h_ {}; 

public:

	explicit FIRFilter(std::vector<double> coeffs);

	// rule of 5; defaults; vectors handles their own memory
	~FIRFilter() noexcept = default;
	FIRFilter(const FIRFilter&) = default;
	FIRFilter(FIRFilter&&) noexcept = default;
	FIRFilter& operator=(const FIRFilter&) = default;
	FIRFilter& operator=(FIRFilter&&) noexcept = default;

	// apply filter
	void applyFilter(const std::vector<double>& input, std::vector<double>& output) const override;

	// grab the impulse response coefficients
	const std::vector<double>& coefficients() const noexcept { return h_; }
};