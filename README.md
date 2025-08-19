# SigProLib
---
## Time-Line and Progression
---
* This project is being built step-by-step so individual functionality will be added once its complete.
* Once all of the components that make up the library have been completed, the library will then be created.
* [Part 1: AverageAmplitude](https://github.com/MRLintern/SigProLib/tree/main/AverageAmplitude)
* [Part 2: SignalRMS](https://github.com/MRLintern/SigProLib/tree/main/SignalRMS)
* [Part 3: SignalVariance](https://github.com/MRLintern/SigProLib/tree/main/SignalVariance)
* [Part 4: SignalSTDDev](https://github.com/MRLintern/SigProLib/tree/main/SignalSTDDev)
* [Part 5: Templated_SignalStatisticsClass](https://github.com/MRLintern/SigProLib/tree/main/Templated_SignalStatisticsClass)
* [Part 6: RunningSumFilter](https://github.com/MRLintern/SigProLib/tree/main/RunningSumFilter)
* [Part 7: ConvolutionAlgo](https://github.com/MRLintern/SigProLib/tree/main/ConvolutionAlgo); in progress.
## Introduction
---
* A `C++17` __Cross-Platform Shared Library__ which can be used to perform basic __Signal Processing Operations__.
* E.g.
  * __Signal Processing Statistics__,
  * ___Convolution___ of two signals and
  * __Time to Frequency Domain__ conversion via the ___Fourier Transform___.
  * TODO.

## Theory
---
### Signal Processing
* TODO.
### Shared Libraries
* TODO.
## Requirements
---
* __OS__: Developed and tested on `Ubuntu 20.04`. However, this will be platform-independent so the software will also be able to run on `Windows 10`.
* __Compiler__: `g++ 13.1.0` on `Linux`. For `Windows 10`, you can use `MinGW` but I recommed using `Windows Subsystem for Linux (WSL)` using the `VSCode` editor.
* `CMake`.
* Understand basic Statistics.
* Understand the foundations of Signal Processing.

## Getting and Using the Software
---
* At the moment, the library hasn't been buit. However, some components have, so you can run these to separately to view the functionality of each component of the future library.
* These individual components can be viewed as `unit tests`; each component isn't large.
* `$ git clone git@github.com:MRLintern/SigProLib.git`
* `cd` into each individual repository to run the program
* TODO.
---
