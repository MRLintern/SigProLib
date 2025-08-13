// driver: main.cpp

#include <iostream>
#include "SignalRMS.hpp"

// number of samples (amplitude components) in the input signal
constexpr std::uint32_t BLOCKSIZE = 320;

// external signal file
extern double InputSignal_f32_1kHz_15kHz[BLOCKSIZE];

int main() {

	double rms_value {0.0};

	// compute RMS of the signal
	SignalRMS(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, &rms_value);

	// output
	std::cout<<"RMS Value of Signal: "<<rms_value<<"\n";
}
