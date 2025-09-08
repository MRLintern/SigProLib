// main.cpp

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <exception>

#include "SignalFileHandler.hpp"
#include "MovingAverageFilter.hpp"
#include "FIRFilter.hpp"
#include "waveforms.hpp"

int main() {

	try {

		// get input samples
		std::unique_ptr<std::vector<double>> input;

		try {

			// attempt to read user-provided samples
			input = SignalFileHandler::LoadFromFile("input_signal.dat");

			std::cout<<"Loaded "<<input->size()<<" samples from input_signal.dat\n";
		} 

		catch (const std::exception&) {

			constexpr double WAVEFORM_LEN {320};

			// fallback: use the compiled-in waveform with 320 samples
			std::cout<<"input_signal.dat not found or unreadable. Using built-in waveforms.cpp data ("<<WAVEFORM_LEN<<" samples).\n";

			input = std::make_unique<std::vector<double>>();
			input->reserve(WAVEFORM_LEN);

			for (std::size_t i{0}; i < WAVEFORM_LEN; ++i) {

				input->push_back(static_cast<double>(InputSignal_f32_1kHz_15kHz[i]));
			}
		}

		// apply moving average filter; window = 11
		MovingAverageFilter maFilter {11};

		std::vector<double> filterOutput;

		maFilter.applyFilter(*input, filterOutput);

		// save results
		SignalFileHandler::SaveToFile(*input, "input_signal.dat");
		SignalFileHandler::SaveToFile(filterOutput, "moving_average.dat");

		std::cout<<"Wrote input_signal.dat and moving_average.dat\n";
	}

	catch (const std::exception& ex) {

		std::cerr<<"FATAL ERROR: "<<ex.what()<<"\n";

		return 1;
	}

	// -- end of main.cpp -- //
}
