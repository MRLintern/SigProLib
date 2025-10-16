#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt


# File paths
input_signal_file = "../Input_Signals/input_signal.dat"
shifted_signal_file = "../Input_Signals/circular_shifted.dat"
correlation_output_file = "circular_correlation_output.dat"


# Load the signals
try:
    input_signal = np.loadtxt(input_signal_file)
    shifted_signal = np.loadtxt(shifted_signal_file)
    circular_corr_output = np.loadtxt(correlation_output_file)
except OSError as e:
    print(f"[ERROR] Could not load one of the files: {e}")
    exit(1)

# Create time index
n_input = np.arange(len(input_signal))
n_shifted = np.arange(len(shifted_signal))
n_corr = np.arange(len(circular_corr_output))


# Create the figure and subplots
plt.figure(figsize=(12, 8))

# First subplot: input signals
plt.subplot(2, 1, 1)
plt.stem(n_input, input_signal, linefmt='b-', markerfmt='bo', basefmt='k-', label='Input Signal', use_line_collection=True)
plt.stem(n_shifted, shifted_signal, linefmt='r-', markerfmt='ro', basefmt='k-', label='Circular Shifted Signal', use_line_collection=True)

plt.title('Input vs Circular Shifted Signal')
plt.xlabel('Sample index (n)')
plt.ylabel('Amplitude')
plt.legend()
plt.grid(True)

#Second subplot: circular correlation output
plt.subplot(2, 1, 2)
plt.stem(n_corr, circular_corr_output, linefmt='g-', markerfmt='go', basefmt='k-', label='Circular Correlation Output', use_line_collection=True)

plt.title('Circular Correlation Output')
plt.xlabel('Lag (n)')
plt.ylabel('Amplitude')
plt.legend()
plt.grid(True)


# Adjust layout and save the figure
plt.tight_layout()
output_plot_file = "circular_correlation_plot.png"
plt.savefig(output_plot_file, dpi=300)
print(f"[INFO] Figure saved as {output_plot_file}")

plt.show()
