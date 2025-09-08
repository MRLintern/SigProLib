// SignalFileHandler.cpp

// implementation file for loading data

#include <vector>
#include <string>
#include <string_view>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <limits>

#include "SignalFileHandler.hpp"

// use std::unique_ptr<std::vector<double>> to make ownership explicit: the caller uniquely owns the loaded samples
std::unique_ptr<std::vector<double>> SignalFileHandler::LoadFromFile(std::string_view path) {

	// convert string_view to std::string; fstreams require a null-terminated path
	std::ifstream in(std::string {path});

	// can't open file
	if (!in) {

		throw std::runtime_error("SignalFileHandler::LoadFromFile: cannot open file: " + std::string {path});
	}

	// create a new empty (data) vector of doubles on the heap; initially empty
	auto data { std::make_unique<std::vector<double>>() };

	// small guess to reduce reallocations for small files
	data->reserve(1024);

	// temporarily hold each number read from the input stream, in
	double value { 0.0 };

	while (in >> value) {

		data->push_back(value);
	}

	// if stream failed NOT due to EOF, then the file contained malformed data
	if (!in.eof()) {

		throw std::runtime_error("SignalFileHandler::LoadFromFile: parse error in file: " + std::string {path});
	}

	// unique ownership of the vector is transferred to the caller
	return data;
}

// save samples to .dat file (1 value/line)
void SignalFileHandler::SaveToFile(const std::vector<double>& data, std::string_view path) {

	std::ofstream out {std::string {path}};

	// can't open output file
	if (!out) {

		throw std::runtime_error("SignalFileHandler::SaveToFile: cannot open file for writing to: " + std::string {path});
	}

	// no problems: write to output file
	for (const double sample : data) {

		out<<sample<<"\n";
	}
}

