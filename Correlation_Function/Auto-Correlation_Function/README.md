## Auto-Correlation and Cross-Correlation Functions
---
### Introduction
---
- ___Correlation___ provides a way for us to measure the __simularity between two signals__ as a function of a __time shift (lag)__.

	- ___Auto-Correlation___: How a signal correlates with itself.
	- ___Cross-Correlation___: How one signal correlates with another time-shifted version of itself.
	
#### Auto-Correlation
---

- __Auto-Correlation__ measures how a signal `x[n]` relates to a __time-shifted version of itself__
- For a discrete-time signal of `length N`:

	- `Rxx[m] = SUM x[n] x[n + m]` between `n = 0` and `N - 1`, where:
	
		- `Rxx[m]` is the auto-correlation at lag `m`,
		- `x[n + m]` is the signal shifted by `m` samples and
		- The lag `m` can be positive or negative.
		
	- If circular behavior is desired, `(n + m)` is taken `modulo N`.
	- __Maximum value at zero lag__: `Rxx[0] corresponds to the ___signal energy___.
	- __Even function__: `Rxx[m] = Rxx[-m]`.
	- Reveals __periodicity__ and __repeating patterns__ in the signal.
	
#### Cross-Correlation
---
- __Cross-Correlation__ measures the similarity between __two different signals__ `x[n]` and `y[n]` as one is shifted in time relative to the other.
- For a discrete-time signal of `length N`:

	- `Rxy[m] = SUM x[n] x[n + m]` between `n = 0` and `N - 1`, where:
	
		- `Rxy[m]` is the cross-correlation at lag `m` and
		- High values indicate strong similarity  (or allignment) between `x[n]` and shifted `y[n]`.
		
	- For periodic signals `(n + m)` can also be taken `modulo N` to compute ___circular-correlation___.
	- `Rxy[m]` is __not necessarily symmetric__.
	- Peak location in `Rxy[m]` indicates the __relative time delay__ between signals.
	- Related to __convolution__ via time reversal.
	
#### Computation
---

- Both versions of correlation can be computed using the ___Fast Fourier Transform (FFT)___:

	- __Auto-Correlation__: `Rxx = F^-1 {X*(k) X(k)}`.
	- __Cross-Correlation__: `Rxy = F^-1 {X*(k) Y(k)}`, where,
	
		- `X(k)` and `Y(k)` are the `FFT`s of `x[n]` and `y[n]`,
		- `X*(k)` is the complex conjugate of `X(k)` and
		- `F^-1` is the inverse FFT.

### Data
* All the data (input and output) can be found in the `results` folder.
* An image of the data post-correlation can be found in the folder too.
* Get rid of the files which have `_output.dat` and run the application to generate the output files and the image.

### Plotting
---
* Inside of the `results` folder, run: `$ python3 plot.py`.
