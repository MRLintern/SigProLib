import numpy as np
import matplotlib.pyplot as plt

# file1.dat
file1 = np.loadtxt('file1.dat')

# file2.dat - this file consists of multiple columns so needs to be flattened 
file2 = np.loadtxt('file2.dat')
file2_flat = file2.flatten()

# ConvolutedSignal.dat
convoluted = np.loadtxt('ConvolutedSignal.dat')

# subplots
fig, axs = plt.subplots(3, 1, figsize=(14, 10), sharex=True)

# Plot file1.dat
axs[0].plot(file1, color='blue')
axs[0].set_title('Original Signal - file1.dat')
axs[0].set_ylabel('Amplitude')
axs[0].grid(True)

# Plot file2.dat
axs[1].plot(file2_flat, color='green')
axs[1].set_title('Original Signal - file2.dat')
axs[1].set_ylabel('Amplitude')
axs[1].grid(True)

# Plot ConvolutedSignal.dat
axs[2].plot(convoluted, color='red')
axs[2].set_title('Convoluted Signal')
axs[2].set_ylabel('Amplitude')
axs[2].set_xlabel('Sample Index')
axs[2].grid(True)

plt.tight_layout()
plt.savefig('convolution_plot.png', dpi=300)
plt.show()