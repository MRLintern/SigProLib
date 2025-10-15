// main.cpp

#include <iostream>
#include <memory>

#include "FileUtility.hpp"
#include "CircularCorrelation.hpp"

int main() {

	try {

		// files that are loaded for circular correlation
		std::string input_signal = "input_signal.dat";
		std::string shifted_input_signal = "circular_shifted.dat";

		// output file for circular correlation result
		std::string output_file = "circular_correlation_output.dat";

		// load files
		auto x = std::make_shared<std::vector<double>>(FileUtility::ReadData(input_signal));
		auto y = std::make_shared<std::vector<double>>(FileUtility::ReadData(shifted_input_signal));

		// tell user about loaded signals
		std::cout<<"Loaded "<<x->size()<<" samples from input_signal.dat\n";
		std::cout<<"Loaded "<<y->size()<<" samples from circular_shifted.dat\n";

		// perform circular correlation calc.
		CircularCorrelation Corr(x, y);
		Corr.Compute();
		Corr.Normalise();

		// save results
		FileUtility::WriteData(output_file, Corr.GetResult());

		std::cout<<"Circular Correlation Completed.\n";

	} catch (const std::exception& e) {

		std::cerr<<"ERROR: "<<e.what()<<"\n";

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
