// main.cpp

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <iomanip>

#include "DFT.hpp"
#include "waveforms.hpp"
#include "constants.hpp"

int main() {

	// allocate memory for a DFT object
	auto dft { std::make_unique<DFT>(SIG_LENGTH) };

	// -- compute the DFT for the signal -- //

	try {

		//dft->ComputeDFT(input);
		dft->ComputeDFT(InputSignal_f32_1kHz_15kHz);

	} catch (const std::exception& e) {

		std::cerr<<"ERROR: Unable to compute DFT: "<<e.what()<<' ';

		return 1;
	}

	// magnitude of 1st half of the frequency bins
	std::vector<double> Magnitude { dft->HalfMagnitude() };

	// compute IDFT
	std::vector<double> idft { dft->ComputeIDFT() };

	// -- open the output files -- //

	std::ofstream f_in("input_signal.dat"); // this is the result of calling IDFT; I.e. an approximation to waveforms.cpp
	std::ofstream f_re("output_rex.dat"); // real components
	std::ofstream f_im("output_imx.dat"); // complex components
	std::ofstream f_mag("output_mag.dat"); // signal magnitude
	std::ofstream f_idft("output_idft.dat"); // inverse discrete fourier transform

	// -- set the precision of the output data -- //
	f_in<<std::setprecision(10);
	f_re<<std::setprecision(10);
	f_im<<std::setprecision(10);
	f_mag<<std::setprecision(10);
	f_idft<<std::setprecision(10);

	// populate frequency bins
	const auto& bins { dft->bins() };

	for (std::size_t i {0}; i < SIG_LENGTH; ++i) {

		f_in<<InputSignal_f32_1kHz_15kHz[i]<<"\n";
		f_re<<bins[i].real()<<"\n";
		f_im<<bins[i].imag()<<"\n";

		if (i < SIG_LENGTH/2) {

			f_mag<<Magnitude[i]<<"\n";
			f_idft<<idft[i]<<"\n";
		}
	}

	std::cout<<"DFT Computed and Results Written to Files\n";
}
