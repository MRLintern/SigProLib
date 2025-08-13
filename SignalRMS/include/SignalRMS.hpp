// function for calculating the root-mean-square (RMS) of a signal

#pragma once

#include <cstdint>

/*

* RMS: a measure of the signals effective magnitude.

* signal_src_arr: pointer to the start of the input signal array

* blockSize: Number of elements (amplitude components) in the signal array

* result: pointer to where the calculated RMS value will be stored

*/

void SignalRMS(const double *signal_src_arr, std::uint32_t blockSize, double *result);
