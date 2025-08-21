// Convolution.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "Convolution.hpp"

// Convolution function to perform convolution
std::vector<double> Convolution::Convolve(const std::vector<double>& signalA, const std::vector<double>& signalB) {

	// size of signals
	size_t nA { signalA.size() };
	size_t nB { signalB.size() };
	size_t nOut { nA + nB - 1 };

	// output signal vector
	std::vector<double> output(nOut, 0.0);

	// perform convolution
	for (size_t n {0}; n < nOut; ++n) {
		for (size_t k {0}; k < nB; ++k) {

			if (n >= k && (n - k) < nA) {

				output[n] += signalA[n - k] + signalB[k];
			}
		}
	}

	return output;
}

// load signal from file
std::vector<double> Convolution::LoadSignal(const std::string& fileName) {

	std::ifstream inFile(fileName);

	// problems opening signal file
	if (!inFile) {

		throw std::runtime_error("ERROR: Unable to open file " + fileName);
	}

	// -- write data to file

	std::vector<double> signal;

	double value {};

	while (inFile >> value) {

		signal.push_back(value);
	}

	return signal;
}

// -- save output signal to file

void Convolution::SaveSignal(const std::vector<double>& signal, const std::string& fileName) {

	// output file object; hold data
	std::ofstream outFile(fileName);

	// issues opening file
	if (!outFile) {

		throw std::runtime_error("ERROR: Unable to open file " + fileName);
	}

	// write data to output file
	for (double sample : signal) {

		outFile<<sample<<"\n";
	}
}

