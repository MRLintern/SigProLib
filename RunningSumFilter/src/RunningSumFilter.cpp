// implement RunningSumFilter class

#include <vector>
#include <fstream>
#include <numeric>
#include <stdexcept>
#include "RunningSumFilter.hpp" 

// function to calculate running sum
std::vector<double> RunningSumFilter::RunningSum(const std::vector<double>& input) {

	std::vector<double> output(input.size());

	// std::partial_sum computes the cumulative sum in 1 clean line
	std::partial_sum(input.begin(), input.end(), output.begin());

	return output;
}

// save results to output file 
void RunningSumFilter::SaveToFile(const std::string& fileName, const std::vector<double>& signal) {

	// output file object
	std::ofstream file(fileName);

	// issues opening file
	if (!file) {

		throw std::runtime_error("Failed to open file Output Signal: " + fileName);
	}

	// write output to file
	for (const auto& value : signal) {

		file<<value<<"\n";
	}
}

// function to load input signal
std::vector<double> RunningSumFilter::LoadFromFile(const std::string& fileName) {

	// input file object
	std::ifstream file(fileName);

	// problems loading file
	if (!file) {

		throw std::runtime_error("Failed to load Input Signal File: " + fileName);
	}

	std::vector<double> signal;

	double value {0.0};

	while (file >> value) { // read 1 double per line

		signal.push_back(value);
	}

	return signal;
}
