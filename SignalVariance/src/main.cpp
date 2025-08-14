// driver: main.cpp

#include <iostream>
#include "SignalVariance.hpp"

constexpr std::uint32_t BLOCKSIZE = 320;

// source signal
extern double InputSignal_f32_1kHz_15kHz[BLOCKSIZE];

int main() {

	// variance statistic of signal
	double variance {0.0};

	// call function to calculate variance of signal
	SignalVariance(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, variance);

	// output
	std::cout<<"Variance of Signal: "<<variance<<"\n";
}
