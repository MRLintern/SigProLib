// Signal.cpp

#include <vector>
#include <memory>
#include <cstddef>

#include "Signal.hpp"
#include "FileUtility.hpp"

// via the Signal constructor move input samples into member variables
Signal::Signal(std::vector<double> samples) : samples_(std::move(samples)) {}

// function to read signal data
std::unique_ptr<Signal> Signal::LoadFromFile(const std::string& fileName) {

	auto data = FileUtility::ReadData(fileName);

	return std::make_unique<Signal>(std::move(data));
}

// get the signal samples
const std::vector<double>& Signal::GetSamples() const {

	return samples_;
}

// return the number of samples in the signal
std::size_t Signal::size() const {

	return samples_.size();
}