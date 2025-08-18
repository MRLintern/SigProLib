// running sum low pass filter
// a class to implement the running sum low pass filter on an input signal

#pragma once

#include <vector>
#include <string>

class RunningSumFilter {

public:

	/*

	- compute the running sum (cumulative sum) of a signal

	- the running sum at index i is the sum of all samples up to i

	- output[i] = input[0] + input[1] + ... + input[i]

	- input: the input signal samples

	- return std::vector<double>: the cummulative sum of the input signal

	*/

	// function to compute running sum
	static std::vector<double> RunningSum(const std::vector<double>& input);

	/*

	- save a signal to a file: 1 sample per line

	- fileName: Name of the output file

	- signal: vector contains signal data

	*/

	// function to save output data to file
	static void SaveToFile(const std::string& fileName, const std::vector<double>& signal);

	// function to load input signal: input_signal.dat
	static std::vector<double> LoadFromFile(const std::string& fileName);

};
