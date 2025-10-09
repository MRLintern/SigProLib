// FileUtility.cpp

#include <vector>
#include <fstream>
#include <stdexcept>

#include "FileUtility.hpp"

// read .dat file into a vector
std::vector<double> FileUtility::ReadData(const std::string& fileName) {

	std::ifstream file(fileName);

	// problems opening the file
	if (!file) {

		throw std::runtime_error("ERROR: Can't open file " + fileName);
	}

	// store samples in data vector
	std::vector<double> data;

	// represents 1 sample/row
	double value;

	// there are 320 samples; 1 sample/row
	while (file >> value) {

		// add samples to data vector
		data.push_back(value);
	}

	// finished adding samples
	return data;
}

// write the vector of output samples to a .dat file; the .dat file contains 1 value/line
void FileUtility::WriteData(const std::string& fileName, const std::vector<double>& data) {

	std::ofstream file(fileName);

	// problems opening file
	if (!file) {

		throw std::runtime_error("ERROR: Can't open file " + fileName);
	}

	// write samples from the vector to the .dat file
	for (auto val : data) {

		file << val << "\n";
	}
}

