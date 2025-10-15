// Signal.hpp

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <cstddef>

// -- represents a 1D discrete-time signal -- //

// * provides functions for loading from the .dat files

class Signal {

private:

	// holds signal samples
	std::vector<double> samples_{};

public:

	// constructor for creating a signal from the vector of signal samples
	explicit Signal(std::vector<double> samples);

	// method to load a signal from the .dat file(s)
	// the signal is loaded via the signals file name
	static std::unique_ptr<Signal> LoadFromFile(const std::string& fileName);

	// get the signal samples
	const std::vector<double>& GetSamples() const;

	// return the length of signal
	std::size_t size() const;

};
