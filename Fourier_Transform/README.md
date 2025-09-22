## Fourier Transform
---
### Introduction
---
* The ___Fourier transform___ is a mathematical tool that takes a signal (a function of time, space, or another variable) and expresses it in terms of its __frequency content__.
    * In the __time domain__, a signal is described by how it changes over time.
    * In the __frequency domain__, the Fourier transform shows which frequencies are present in the signal and how strong they are.
* Essentially, it breaks down a complicated waveform into a __sum of simple sinusoids__ (__sines__ and __cosines__) of different __frequencies__, __amplitudes__, and __phases__.
* Key ideas:
    * It’s like taking a "recipe" of __frequencies__ that make up a signal.
    * __High frequencies__ correspond to __rapid changes__, while __low frequencies__ describe __slow variations__.
    * It’s widely used in physics, engineering, and data analysis — for example, in signal processing, image compression, quantum mechanics, and solving differential equations.
 
* We'll be looking at the ___Discrete Fourier Transform___ and the ___Fast Fourier Transform___.

* Note: the data which is used for this application is `ECG data`.

### Theory
---
#### Discrete Fourier Transform
* Converts a __finite sequence__ of numbers (often samples of a __signal__ in __time__ or __space__) into a __sequence__ of __complex numbers__ representing its __frequency components__.

#### Fast Fourier Transform
* An algorithm to compute the __DFT much more efficiently__, reducing the __complexity__ from `O(N^2)` to `O(NlogN)`.
* It works by __recursively__ breaking down a __large DFT__ into __smaller ones__ (often exploiting __symmetries__ in the __complex exponentials__).
* The most common __FFT algorithm__ is the ___Cooley–Tukey Algorithm___, which is especially efficient when `N` is a power of 2.

### Running the Application
---
* TODO.
