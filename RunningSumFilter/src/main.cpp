// driver: main.cpp

#include <iostream>
#include "RunningSumFilter.hpp"

int main() {

	try {

		// load input signal from file
		auto input { RunningSumFilter::LoadFromFile("input_signal.dat") };

		// compute running sum calculation
		auto output { RunningSumFilter::RunningSum(input) };

		// save (computed) output signal
		RunningSumFilter::SaveToFile("output_signal.dat", output);

		// message to tell user whats been done
		std::cout<<"Processed "<<input.size()
			     <<" Samples. Output written to output_signal.dat\n";

	} catch (const std::exception e) {

		std::cerr<<"ERROR: "<<e.what()<<"\n";

		return 1;
	}	
}
