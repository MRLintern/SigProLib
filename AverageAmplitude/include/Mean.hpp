// finds the average amplitude of a signal/waveform

#pragma once

#include <cstdint> // for std::uint32_t

/*

signal_src_arr: pointer to the input signal array.

blockSize: Number of elements (amplitude components) in the input signal array.

result: pointer to where the result will be stored.

finding the mean amplitude value:

	mean = sum of all amplitudes / number of samples

*/

// function finds the average amplitude of the signal/waveform
void SignalMean(const double *signal_src_arr, std::uint32_t blockSize, double *result);
