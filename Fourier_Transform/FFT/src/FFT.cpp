
// FFT.cpp

#include <cmath>
#include <complex>
#include <stdexcept>
#include <algorithm>

#include "FFT.hpp"
#include "constants.hpp"

// -- helper functions -- //

std::size_t FFT::PowerOfTwo(std::size_t n) {

    // returns smallest power of two >= n
    if (n == 0) { return 1; }

    --n;

    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

#if SIZE_MAX > UINT32_MAX

    n |= n >> 32;

#endif

    return ++n;
}

// reverse bits
std::size_t FFT::BitReversal(std::size_t x, unsigned int bits) {

    // reverse the lower 'bits' bits of x; used for bit-reversal permutation
    std::size_t y {0};

    for (unsigned int i {0}; i < bits; ++i) {

        y = (y << 1) | (x & 1);

        x >>= 1;
    }

    return y;
}

// iterative in-place Cooley-Tukey FFT
// if inverse == true; computes IFFT; caller divides N after call
void FFT::IterativeFFT(std::vector<Complex>& data, bool inverse) const {

    const std::size_t N { data.size() };

    if (N == 0) { return; }

    // compute number of bits needed for indices
    unsigned int bits {0};

    std::size_t tmp {N};

    while (tmp > 1) { tmp >>= 1; ++bits; }

    // bit-reversal permutation
    for (std::size_t i {0}; i < N; ++i) {

        std::size_t j { BitReversal(i, bits) };

        if (j > i) { std::swap(data[i], data[j]); }
    }

    // main loop: length = 2, 4, 8, ..., N
    for (std::size_t len {2}; len <= N; len <<= 1) {

        // angle step; -ve for FFT and +ve for IFFT
        double angleStep { (inverse ? 2.0 : -2.0) * PI / static_cast<double>(len) };

        // rotate angle through the complex plane
        Complex angleRotate(std::cos(angleStep), std::sin(angleStep));

        for (std::size_t i {0}; i < N; i += len) {

            Complex ang(1.0, 0.0);

            std::size_t half { len >> 1 };

            for (std::size_t j {0}; j < half; ++j) {

                Complex u { data[i + j] };
                Complex v { data[i + j + half] * ang };

                data[i + j] = u + v;
                data[i + j + half] = u - v;

                // advance the rotated angle
                ang *= angleRotate;
            }
        }
    }
}

// compute FFT algorithm
std::vector<FFT::Complex> FFT::ComputeFFT(const std::vector<double>& TimeSamples) {

    // zero-pad to power-of-two length
    const std::size_t OriginalN { TimeSamples.size() };
    const std::size_t N { PowerOfTwo(OriginalN) };

    // complex buffer with zero-padding
    std::vector<Complex> data(N, Complex(0.0, 0.0));

    for (std::size_t i {0}; i < OriginalN; ++i) {

        // calc. the complex component of the (real) time-samples
        data[i] = Complex(TimeSamples[i], 0.0);
    }

    // implement iterative FFT algorithm
    IterativeFFT(data, false);

    return data; // frequency-domain bins - size = N
}

// compute the IFFT algorithm
std::vector<double> FFT::ComputeIFFT(const std::vector<Complex>& FrequencyBINS) {

    // make a copy because we perform in-place operations
    // the frequency bins are complex numbers; data type
    std::vector<Complex> data = FrequencyBINS;

    const std::size_t N { data.size() };

    if (N == 0) { return {}; }

    // compute IFFT conjugation + forward FFT + conjugation or directly with inverse flag
    IterativeFFT(data, true);

    // normalise by N and take real parts
    std::vector<double> output(N);

    for (std::size_t i {0}; i < N; ++i) {

        output[i] = data[i].real() / static_cast<double>(N);
    }

    return output;
}

// for finding the magnitude of half the frequency bins
std::vector<double> FFT::HalfMagnitude(const std::vector<Complex>& bins) {

    // represents half of the frequency bins
    std::size_t half { bins.size() / 2 };
    
    // represents the magnitude of half the frequency bins
    std::vector<double> magnitude(half);

    for (std::size_t i {0}; i < half; ++i) {

        // calc. magnitude of half of the frequency bins
        magnitude[i] = std::abs(bins[i]);
    }

    return magnitude;
}



