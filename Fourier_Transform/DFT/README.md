## Discrete Fourier Transform (DFT)
---
* This repository contains the software for implementing the ___Discrete Fourier Transform (DFT)___.

### Results
---
* The `results` have been included for viewing.
* However, if you run the software you will generate these and they can be found in the `build` directory.
* TODO: the software will (probably) be altered so that the output files are sent to a separate appropriate directory.

### Plotting
---
* To plot the results:
* `$ python3 plot.py`
* However, you can see a copy of this provided in this repository.

### Running the Application
* Assuming you've cloned the project.
* `$ cd Fourier_Transform && cd DFT`.
* Get rid of the build directory (if you want to generate your own plots).
* `$ rm -rf build`.
* build the application:
* `$ mkdir build -p && cd build`.
* `$ cmake ..`.
* `$ cmake --build .`.
* `$ ./main`.
