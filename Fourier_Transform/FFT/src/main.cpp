// main.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <memory>

#include "FFT.hpp"
#include "waveforms.hpp"
#include "constants.hpp"

int main() {

	// create an FFT object
	auto fft = std::make_unique<FFT>();

	// copy in input signal
	std::vector<double> input(InputSignal_f32_1kHz_15kHz.begin(), InputSignal_f32_1kHz_15kHz.end());

	// compute FFT
	auto FrequencyBINS = fft->ComputeFFT(input);

	// calculate the magnitude of half the frequency bins
	auto magnitude = FFT::HalfMagnitude(FrequencyBINS);

	// compute inverse FFT; IFFT => time-domain reconstruction; this should match the original source/input signal
	auto ReconTimeSamples = fft->ComputeIFFT(FrequencyBINS);

	// -- open output files -- //

	std::ofstream f_in("input_signal.dat"); // time-domain
	std::ofstream f_re("output_rex.dat"); // real-component of frequency bins
	std::ofstream f_im("output_imx.dat"); // imaginary components of frequency bins
	std::ofstream f_mag("output_mag.dat"); // magnitude of frequency spectrum
	std::ofstream f_ifft("output_ifft.dat"); // output of IFFT

	// -- precision of output data files -- //

	f_in<<std::setprecision(10);
	f_re<<std::setprecision(10);
	f_im<<std::setprecision(10);
	f_mag<<std::setprecision(10);
	f_ifft<<std::setprecision(10);

	// -- write output data to files -- //

	// for mean-squared-error (MSE)
	double mse {0.0};

	for (std::size_t i {0}; i < SIG_LENGTH; ++i) {

		f_in<<input[i]<<"\n";

		// frequency bins; complex plane (real + imaginary)
		f_re<<FrequencyBINS[i].real()<<"\n";
		f_im<<FrequencyBINS[i].imag()<<"\n";

		// IFFT
		f_ifft<<ReconTimeSamples[i]<<"\n";

		// calc. error
		double error = (input[i] - ReconTimeSamples[i]);

		// calc. MSE
		mse += error * error;

		// magnitude for half of frequency spectrum
		if (i < SIG_LENGTH / 2) {

			f_mag<<magnitude[i]<<"\n";
		}
	}

	// normalise error by number of samples
	mse /= SIG_LENGTH;

	std::cout<<"FFT Completed. All Output Printed to Files.\n";
	std::cout<<"The Mean-Squared-Error Between the Input and the IFFT Output is: "<<mse<<"\n";
}
