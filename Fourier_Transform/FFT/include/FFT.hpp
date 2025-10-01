// FFT.hpp

// Algorithm used: Cooley-Tukey
// Expresses the DFT in terms of smaller DFTs recursively.
// This reduces the computation time from O(N^3) to O(N log N)

#include <vector>
#include <complex>
#include <cstddef>

class FFT {

public:

	// alias for complex numbers
	using Complex = std::complex<double>;

private:

	// -- mutator functions -- //

	static std::size_t PowerOfTwo(std::size_t n);
	static std::size_t BitReversal(std::size_t x, unsigned int bits);

	// iterative FFT
	void IterativeFFT(std::vector<Complex>& data, bool inverse) const;

public:

	// FFT object for problem-size N
	explicit FFT() = default;

	// Compute FFT
	// input: real-valued time-sampled data
	// output: complex-valued; data in the frequency domain stored in bins

	std::vector<Complex> ComputeFFT(const std::vector<double>& TimeSamples);

	// Compute the Inverse of the FFT: IFFT:
	// input: complex-valued; data in the frequency domain stored in bins
	// output: real-valued time-sampled data

	std::vector<double> ComputeIFFT(const std::vector<Complex>& FrequencyBINS);

	// magnitude of 1st half of frequency bins
	static std::vector<double> HalfMagnitude(const std::vector<Complex>& bins);
};