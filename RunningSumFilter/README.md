## Running Sum Low Pass Filter
---

### Introduction
---
* The __Running Sum__ (AKA __Moving Sum__) is a simple ___Finite Impulse Response (FIR) Low-Pass Filter___.
* Mathematically, for an input signal, `x[i]`:

    `y[i] = x[n] + x[n - 1] + ... + x[n - (M - 1)]`, where:
    * __y__ is the __Output Signal__.
    * __M__ = Window Length,
    * If __M = Infinity__ you get the __cumulative sum__.
    * If __M__ is __Finite__, you get a __Sliding Window Moving Average__.
 
### What does it ___do___?
---
* It __smooths out rapid changes__ (__high frequencies__).
* It __passes Low-Frequency__ content relatively unchanged.
* It __Attenuates High-Frequency__ content, acting like a __Low-Pass Filter__.
* The longer the window length M, the __stronger the Smoothing__ and the __Lower the Cutoff Frequency__.

### Using the Software
---
* TODO.
---

