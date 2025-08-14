// driver: main.cpp; find the standard deviation of the input signal

#include <iostream>
#include "SignalSTDDev.hpp"

// number of frequency components to be sampled
constexpr std::uint32_t BLOCKSIZE = 320;

// waveform (signal)
extern double InputSignal_f32_1kHz_15kHz[BLOCKSIZE];

int main() {

	// mean value
	double amplitudeMean {0.0};

	// variance
	double amplitudeVariance {0.0};

	// standard deviation
	double amplitudeSTDDev {0.0};

	// call function to calculate the mean of the input signal
	SignalMean(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, &amplitudeMean);

	// call function to calculate variance of signal
	SignalVariance(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, amplitudeVariance);

	// call function to calculate standard deviation of signal
	SignalSTDDev(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, amplitudeSTDDev);

	// -- output results (signal statistics)

	// mean
	std::cout<<"Average Amplitude of Signal: "<<amplitudeMean<<"\n";

	// variance
	std::cout<<"Variance of Signal's Amplitude: "<<amplitudeVariance<<"\n";

	// standard deviation
	std::cout<<"Standard Deviation of Signal's Amplitude: "<<amplitudeSTDDev<<"\n";
}
