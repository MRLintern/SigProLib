// main.cpp

#include <iostream>
#include "Convolution.hpp"

/*

- load input and impulse response signals
- perform convolution and save output

*/

int main() {

	try {

		// load input files
		auto inputSignal { Convolution::LoadSignal("file2.dat") };
		auto impulseResponse { Convolution::LoadSignal("file1.dat") };

		// output: tell user about size of the files
		std::cout<<"Loaded input signal of size "<<inputSignal.size()<<"\n";
		std::cout<<"Loaded impulse signal of size "<<impulseResponse.size()<<"\n";

		// perform convolution
		//auto convolutedSignal { Convolution::Convolve(file1, file2) };
		auto convolutedSignal { Convolution::Convolve(inputSignal, impulseResponse) };

		std::cout<<"Convolution complete\n";

		// save results to file
		Convolution::SaveSignal(convolutedSignal, "ConvolutedSignal.dat");

		// tell user data written to file
		std::cout<<"Output written to ConvolutedSignal.dat\n";

	} 	catch (const std::exception e) {

		std::cerr<<e.what()<<"\n";

		return EXIT_FAILURE;
	}
}

// -- end of program (main.cpp)
