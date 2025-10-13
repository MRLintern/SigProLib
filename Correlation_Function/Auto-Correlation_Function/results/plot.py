#!/usr/bin/env python3

# plot_correlations.py

# plotting the output signals post auto- and cross-correlation

import numpy as np
import matplotlib.pyplot as plt


# function to load .dat files

def LoadSignal(file_path):
    
    return np.loadtxt(file_path)


# Load the data files

signal1 = LoadSignal("input_signal.dat")
signal2 = LoadSignal("circular_shifted.dat")
auto_corr = LoadSignal("autoCorrelation_output.dat")
cross_corr = LoadSignal("crossCorrelation_output.dat")


# x-axis arrays

n_samples = len(signal1)
n = np.arange(n_samples)
lags = np.arange(n_samples)


# subplots (stacked vertically)

fig, axes = plt.subplots(3, 1, figsize=(12, 10))
fig.suptitle("Input Signals and Correlation Results", fontsize=16, fontweight='bold')


# Subplot 1: Input signals

axes[0].stem(n, signal1, basefmt=" ", linefmt="C0-", markerfmt="C0o", use_line_collection=True, label="Input Signal 1")
axes[0].stem(n, signal2, basefmt=" ", linefmt="C1--", markerfmt="C1s", use_line_collection=True, label="Circular Shifted Signal")
axes[0].set_title("Original and Circularly Shifted Signals")
axes[0].set_xlabel("Sample Index (n)")
axes[0].set_ylabel("Amplitude")
axes[0].grid(True, linestyle=':')
axes[0].legend(loc="upper right")


# Subplot 2: Auto-correlation

axes[1].stem(lags, auto_corr, basefmt=" ", linefmt="C2-", markerfmt="C2o", use_line_collection=True, label="Auto-Correlation")
axes[1].set_title("Auto-Correlation of Signal 1")
axes[1].set_xlabel("Lag")
axes[1].set_ylabel("Correlation Amplitude")
axes[1].grid(True, linestyle=':')
axes[1].legend(loc="upper right")


# Subplot 3: Cross-correlation

axes[2].stem(lags, cross_corr, basefmt=" ", linefmt="C3-", markerfmt="C3o", use_line_collection=True, label="Cross-Correlation")
axes[2].set_title("Cross-Correlation between Signal 1 and Signal 2")
axes[2].set_xlabel("Lag")
axes[2].set_ylabel("Correlation Amplitude")
axes[2].grid(True, linestyle=':')
axes[2].legend(loc="upper right")


plt.tight_layout(rect=[0, 0, 1, 0.96]) 
plt.savefig("correlation_results.png", dpi=300, bbox_inches='tight')
plt.show()
