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
* [Part 7: ConvolutionAlgo](https://github.com/MRLintern/SigProLib/tree/main/ConvolutionAlgo)
* [Part 8: Finite Impulse Response (FIR) Filter](https://github.com/MRLintern/SigProLib/tree/main/FIR_Filter)
* [Part 9: Fourier Transform](https://github.com/MRLintern/SigProLib/tree/main/Fourier_Transform) 
* [Part 10: Correlation Function](https://github.com/MRLintern/SigProLib/tree/main/Correlation_Function); There are many types; I'll be looking at 2 types: ___Auto-Correlation___ & ___Circular-Correlation___; in progress.
## Introduction
---
* A `C++17` __Cross-Platform Shared Library__ which can be used to perform basic __Signal Processing Operations__.
* E.g.
  * __Signal Processing Statistics__,
  * __Finite Impulse Response (FIR) Filter__,
  * ___Convolution___ of two signals and
  * __Time to Frequency Domain__ conversion via the ___Fourier Transform___.
  
## Source Data
---
* __Data__: all the input signals/data come from a 3rd year course I took while studying at the University of Liverpool: ___Signal Processing & Exploration Seismology___.
* Click [here](https://github.com/MRLintern/SigProLib/tree/main/Source_Date) to see the source files used in this project.
* This will be updated continuously as the project continues.
## Theory
---
### Signal Processing
* A __signal__ is any __time-varying__ or __spatial quantity__ that carries information — e.g., sound, image, video, biomedical data, or sensor measurements.
* __Processing__: applying __mathematical operations__ (__filtering__, __compression__, __detection__, __transformation__, etc.) to extract useful information or improve the signal.
* At its core, DSP involves:
   - __Sampling__ (converting __continuous signals__ into __discrete data__ using an ADC — analog-to-digital converter.
   - __Processing__ the data using __algorithms__ (e.g., __convolution__, __Fourier transform__, __filtering__).
   - __Reconstructing__ or __interpreting__ the signal (possibly converting back to analog via a DAC — digital-to-analog converter).
* __Application__: E.g.
   - __Geophysics__: __Seismic Data Processing__: computational methods used to __transform raw seismic recordings__ into clear, __interpretable images__ of the __Earth's subsurface__. This is the first stage in creating __Geological Models__ which can be __interpreted__ in order to find __Oil & Gas traps__ in __Sandstone Reservoirs__.
### Shared Libraries
---
* I thought I'd a few notes r.e. what __shared libraries__ are if you're interested.
* A ___Shared Library___ is a collection of precompiled code that multiple programs can use at runtime, instead of each program having to include its own copy.
* Instead of embedding the library into your program’s binary (__static linking__), the code lives in a separate file on the system.
* At runtime, the operating system loads the library into memory and links it to your program.
* Many processes can share the same library in memory at the same time which means: saves memory and disk space.
#### Shared Libraries in Linux
* The file extension is `so`, short for ___Shared Object___.
* E.g., `libm.so`, the __math library__.
##### How it Works
* When you compile with `-shared`, you build a `.so` file.
* At runtime, the __dynamic linker__ (`ld-linux.so`) finds and loads the library.
* Programs reference the symbols (functions, variables) from it.
* E.g.
   * `$ g++ -fPIC -shared -o libmylib.so mylib.cpp`
   * `$ g++ main.cpp -L. -lmylib -o myprogram`
   * `$ LD_LIBRARY_PATH=. ./myprogram`
  
* `libmylib.so` is the shared library.
* `LD_LIBRARY_PATH` tells the system where to find it.

#### Shared Libraries in Windows
* File extension: `.dll` for ___Dynamic-Link Library___.
* At runtime, Windows loads the `.dll` into the process.
* Programs can call its exported functions.
* E.g. `myLib.cpp`:
  
    * `__declspec(dllexport) void hello() {
            std::cout << "Hello from DLL!\n";
      }`
 * Compile `myLib.cpp` into `myLib.dll`.
 * Programs that use it link against `mylib.lib` (import library).
        

## Requirements
---
* __OS__: Developed and tested on `Ubuntu 20.04`. However, this will be platform-independent so the software will also be able to run on `Windows 10`.
* __Compiler__: `g++ 13.1.0` on `Linux`. For `Windows 10`, you can use `MinGW` but I recommed using `Windows Subsystem for Linux (WSL)` using the `VSCode` editor.
* `CMake`.
* Understand basic __Statistics__; the theory won't be covered so you'll need to know this stuff.
* Understand the foundations of __Signal Processing__; the theory won't be covered so you'll need to know this stuff.

## Future Work and Development
---
* `C++17` is being used to develop this software.
* However, given the nature of the project, `C++20` or even `C++23`, might be worth using because of the new feature of `modules`, introduced in `C++20`.
* TODO.
## Getting and Using the Software
---
* At the moment, the library hasn't been buit. However, some components have, so you can run these to separately to view the functionality of each component of the future library.
* `$ git clone git@github.com:MRLintern/SigProLib.git`
* `cd` into each individual repository to run the program.
---
