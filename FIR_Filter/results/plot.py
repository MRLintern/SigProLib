#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt


# function to load .dat files 
def load_signal(file_path):
    """Loads a 1D signal from a .dat file into a NumPy array."""
    return np.loadtxt(file_path)


# Load input and filtered signals
input_file = "input_signal.dat"
output_file = "moving_average.dat"

input_signal = load_signal(input_file)
filtered_signal = load_signal(output_file)


# Create time/sample index
n_input = np.arange(len(input_signal))
n_output = np.arange(len(filtered_signal))


# figure with two subplots (input + output)
plt.figure(figsize=(12, 8))

# Input Signal
plt.subplot(2, 1, 1)
plt.plot(n_input, input_signal, color='tab:blue', linewidth=1.5, label='Input Signal')
plt.title('Input Signal (Before Filtering)')
plt.xlabel('Sample Index (n)')
plt.ylabel('Amplitude')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.7)

# Subplot 2: Filtered Output Signal
plt.subplot(2, 1, 2)
plt.plot(n_output, filtered_signal, color='tab:red', linewidth=1.5, label='Filtered Output (Moving Average)')
plt.title('Output Signal (After Moving Average FIR Filter)')
plt.xlabel('Sample Index (n)')
plt.ylabel('Amplitude')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.7)


plt.tight_layout()
plt.savefig("moving_average_filter_plot.png", dpi=300, bbox_inches='tight')
plt.show()
