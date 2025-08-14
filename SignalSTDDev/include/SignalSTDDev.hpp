/*

SignalSTDDev.hpp

Functions that calculate:

- Mean amplitude

- Amplitude Variance

- Amplitude Standard Deviation

- Arguments for the functions

* signal_src_arr: pointer to the start of the input signal

* blockSize: number elements (amplitude components) in the signal array

* result: reference to where the calculated variance value will be stored

*/

#pragma once 

#include <cstdint>
#include <vector>

// function finds the average amplitude of the signal/waveform
void SignalMean(const double *signal_src_arr, std::uint32_t blockSize, double *result);

// function calculates the variance of the variance of the amplitude components
void SignalVariance(const double *signal_src_arr, std::uint32_t blockSize, double &result);

// overloading: if we store the signal in a vector (container) we can use this:
double SignalVariance(const std::vector<double>& signal);

// function calculates the standard deviation of the signal
void SignalSTDDev(const double *signal_src_arr, std::uint32_t blockSize, double &result);

// Optional: overloading SignalSTDDev function when the signal is stored in a vector
double SignalSTDDev(const std::vector<double>& signal);



