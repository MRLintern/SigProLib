#include <iostream>
#include <cstdint> // for std::uint32_t
#include "Mean.hpp"

// number of frequency components to be sampled
constexpr std::uint32_t BLOCKSIZE = 320;

// waveform (signal)
extern double InputSignal_f32_1kHz_15kHz[BLOCKSIZE];

int main() {

	// mean (average) value
	double mean {};

	// call function to calculate the mean of the input signal
	SignalMean(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, &mean);

	// output result
	std::cout<<"The Average/Mean Amplitude of the Signal is: "<<mean<<"\n";
}
