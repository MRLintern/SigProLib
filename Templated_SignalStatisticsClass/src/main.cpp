// driver: main.cpp

#include <iostream>
#include <memory>
#include "SignalStatistics.hpp"

// number of amplitude components making up the signal
constexpr std::size_t BLOCKSIZE = 320; 

// source signal
extern double InputSignal_f32_1kHz_15kHz[BLOCKSIZE];

int main() {

	try {

		// template takes in a type of double; source pointer
		auto sourceSignal = std::make_unique<SignalStatistics<double>>(InputSignal_f32_1kHz_15kHz, BLOCKSIZE);

		// -- calculate signal statistics -- //

		// Mean
		double signalMean = sourceSignal -> SignalMean();

		// variance
		double signalVariance = sourceSignal -> SignalVariance();

		// standard deviation
		double signalSTDDev = sourceSignal -> SignalSTDDev();

		// -- output results

		// mean
		std::cout<<"Average Amplitude of the Signal is: "<<signalMean<<"\n";

		// variance
		std::cout<<"Variance of Signal Amplitude is: "<<signalVariance<<"\n";

		// standard deviation
		std::cout<<"Standard Deviation of Signal Amplitude is: "<<signalSTDDev<<"\n";
	}

	catch (const std::exception& e) {

		std::cerr<<"ERROR: "<<e.what()<<"\n";
	}
}

