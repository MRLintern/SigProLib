## Circular-Correlation
---

### Introduction
---

- Like the ___Linear Correlation___ algorithm developed, it is used to measure the __similarity between two periodic signals__ by allowing one signal to __wrap around__ during the correlation operation.

- With __linear correlation__, where signals are compared over a finite window, ___circular correlation___ assumes the signals are periodic.

### Mathematical Form
---

- For two discrete-time signals `x[n]` and `y[n]` of length `length N`, their __circulation correlation__ is defined as:

	- `Rxy[m] = SUM{ x[n] y[(n + m) mod N]}`, between `n = 0` and `N - 1`, where,
	
		- `m` is the lag (shift),
		- `mod` ensures wrapping around the signal length and
		- `Rxy[m]` gives the similarity measure at lag `m`.
		
- This differs from linear correlation because the signals are not zero-padded beyond their original length: they're ___wrapped around___.

### Running the Application
---
- The input signals will be moved to another folder.
- `$ mkdir build && cd build`
- `$ cmake ..`
- `$ cmake --build .`
- `$ ./main input_signal.dat circular_shifted.dat`

### Results and Plotting
---
- When you run the application, the output file(s) are placed in the `build` directory.
- Either run the `Python` script in the `build` folder, or move the files and plotting script to an appropriate folder.
- Plotting: `$ python3 plot.py`.
- In the `results-data` directory, you'll find a `.png` image of the output.
