// FileUtility.hpp

#pragma once

#include <string>
#include <vector>

// -- function for reading .dat files and writing to .dat files -- //

class FileUtility {

public:

	// * the following function will read input signal (.dat files)
	// * function argument: the .dat files are read into vector containers
	// * another function argument is the path to input .dat files/signals
	// * the function returns a vector containing the loaded signal samples

	static std::vector<double> ReadData(const std::string& fileName);

	// * the following function will write output signal data to a .dat file
	// * the function argument is the path to the output .dat files/signals
	// * another function argument: signal data the vector writes to

	static void WriteData(const std::string& fileName, const std::vector<double>& data);
};
