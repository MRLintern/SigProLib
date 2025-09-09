# Finite Impulse Response Filter
---
## Introduction
---
* Here we create a ___Finite Impulse Response (FIR) Filter___ by means of using a ___Moving Average___.

## Theory
---
* A ___Finite Impulse Response (FIR) Filter___ is a type of digital filter.
* __Definition__:
  - An __FIR filter__ produces an output that is a __weighted sum__ of a finite number of past input samples.
  - The “finite” part means it only uses a limited number of input values (the filter order) and does not rely on feedback from past outputs.
* __Mathematical form__:

  - `y[n] = SUM{b[k] * x[n - k]`, where:
  - `y[n]` = filter output at time `n`,
  - `x[n]` = input signal at time `n`,
  - `b[k]` = filter coefficients (the "weights") and
  - `SUM` = the summation symbol, `sigma`, which ranges from `k = 0` to `M`, where `M` represents the filter order (number of `taps - 1`).
* __What it does__:
  - __FIR filters__ allow us to __selectively attenuate__ or __amplify parts__ of a __signal’s frequency__ content.
  - E.g. removing __high-frequency noise__ (__low-pass__), __blocking DC offset__ (__high-pass__), or isolating a __frequency band__ (__band-pass__).


## Running the Software
---
* Assuming you've clone the repository:
* `$ git clone git@github.com:MRLintern/SigProLib.git`
* `$ cd FIR_Filter`
* `$ mkdir build -p && cd build`
* `$ cmake ..`
* `$ cmake --build .`
---
