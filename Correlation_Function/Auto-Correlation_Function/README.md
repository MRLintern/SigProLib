## Auto-Correlation and Cross-Correlation Functions
---
### Introduction
---
* This sub-repository consists of the ___auto-correlation___ and ___cross-correlation algorithms___.

### Running the Application
---
* `$ mkdir build && cd build`
* `$ cmake ..`
* `$ cmake --build .`
* `$ ./main input_signal.dat circular_shifted.dat`
* The results, `autoCorrelation_output.dat` `crossCorrelation_output.dat`, will be inside the `build` directory.

### Data
* All the data (input and output) can be found in the `results` folder.
* An image of the data post-correlation can be found in the folder too.
* Get rid of the files which have `_output.dat` and run the application to generate the output files and the image.

### Plotting
---
* Inside of the `results` folder, run: `$ python3 plot.py`.
