## Correlation Function
---

### What is it?
---
* The ___Correlation Function___ measures the __similarity between two signals__ (or a __signal with itself__, in which case it’s called __autocorrelation__) as one signal is shifted relative to the other.
* Essentially you're asking:
    - ___"If I slide one signal past the other, how similar are they at each shift (lag)?"___
### What does it do?
---
* The correlation function is used to detect __similarity__, __patterns__, or __periodicity in signals__.
* Specifically, it helps with:
  1. __Measuring Similarity__
    - High correlation → signals are similar at that shift.
    - Low correlation → signals are unrelated or misaligned.
  2. __Detecting Time Delay / Alignment__
    - In applications like radar, sonar, and wireless comms, cross-correlation finds how much one signal is delayed relative to another.
  3. __Feature Detection__
    - In pattern recognition or image processing, correlation is used to detect known templates in data.
  4. __Periodicity Detection__
    - Autocorrelation peaks indicate repeating patterns, fundamental frequency (e.g., pitch detection in audio).
  5. __Noise Analysis__
    - Autocorrelation can help distinguish signal from random noise (noise tends to decorrelate quickly, while structured signals show strong correlation).
  ### Correlation Types
  ---
  - __Autocorrelation__: ___"How much does the signal look like a shifted version of itself?"___
  - __Cross-Correlation__: ___"How much does one signal look like another, if I shift it back and forth?"___
  
