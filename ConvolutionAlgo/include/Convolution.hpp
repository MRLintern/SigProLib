// Convolution.hpp

// class for performing convolution of 2 signals

#pragma once

#include <vector>

class Convolution {

public:

	/*

	- signalA: 1st (main) input signal
	- signalB: 2nd (impulse-response) input signal
	- returned signal post-convolution: length = A.size() + B.size() - 1

	*/

	// function to convolve signals
	static std::vector<double> Convolve(const std::vector<double>& signalA, const std::vector<double>& signalB);

	// load a signal from a text file; save signal samples to a vector
	static std::vector<double> LoadSignal(const std::string& fileName);

	// save output signal to a text file
	static void SaveSignal(const std::vector<double>& signal, const std::string& fileName);	
};
