// main.cpp

#include <iostream>
#include <stdexcept>

#include "Signal.hpp"
#include "FileUtility.hpp"
#include "Correlation.hpp"

// --- algorithm to follow --- //

// 1. loads 2 .dat files containing signal samples
// 2. first file: computes auto-correlation
// 3. computes cross-correlation between both signal samples
// 4. output results; these will be plotted 

// -------------------------------- //

int main(int argc, char* argv[]) {

	// we can only accept 2 arguments; i.e. the 2 .dat files
	if (argc < 3) {

		std::cerr<<"Requires: "<<argv[0]<<" <file1.dat> <file2.dat>\n";

		return 1;
	}

	try {

		// 1. load the 2 signals

		auto signal1 = Signal::LoadFromFile(argv[1]);
		auto signal2 = Signal::LoadFromFile(argv[2]);

		// input signals must be the same size
		if (signal1->size() != signal2->size()) {

			std::cerr<<"ERROR: Signals must be the same size.\n";

			return 1;
		}

		std::cout<<"Samples loaded.\n";

		// 2. compute the auto-correlation of signal1

		auto autoCorrelation = Correlation::AutoCorrelation(*signal1, true);

		std::cout<<"Auto-Correlation of Signal 1 Completed.\n";

		// 3. compute the cross-correlation between both signals

		auto crossCorrelation = Correlation::CrossCorrelation(*signal1, *signal2, true);

		std::cout<<"Cross-Correlation of both Signals Completed.\n";

		// 4. output the results (for plotting later)

		FileUtility::WriteData("autoCorrelation_output.dat", *autoCorrelation);
		FileUtility::WriteData("crossCorrelation_output.dat", *crossCorrelation);

		std::cout<<"Results Written to Files: autoCorrelation_output.dat and crossCorrelation_output.dat\n";

		// print out some results to verify success
		std::cout<<"\nFirst 10 Normalised Auto-Correlation Values:\n";

		for (std::size_t i {0}; i < 10 && i < autoCorrelation->size(); ++i) {

			std::cout<<"Lag "<<i<<" : "<<(*autoCorrelation)[i]<<"\n";
		}

		// print out some results to verify success
		std::cout<<"\nFirst 10 Normalised Cross-Correlation Values:\n";

		for (std::size_t i {0}; i < 10 && i < crossCorrelation->size(); ++i) {

			std::cout<<"Lag "<<i<<" : "<<(*crossCorrelation)[i]<<"\n";
		}

	// catch errors; e.g. missing files etc
	} catch (const std::exception& e) {

		std::cerr<<"EXCEPTION: "<<e.what()<<"\n";

		return 1;
	}
}
