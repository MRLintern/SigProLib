// IFilter.hpp


#pragma once

/*

- Polymorphic interface for signal filters

*/

#include <vector>

class IFilter {

public:

	virtual ~IFilter() = default;

	// apply filter to input and write to output
	virtual void applyFilter(const std::vector<double>& input, std::vector<double>& output) const = 0;
};
