# Discrete Fourier Transform & Fast Fourier Transform Analysis

Welcome to my analysis of the Discrete Fourier Transform (DFT) and Fast Fourier Transform (FFT)!

In this Repo, you can find a research paper describing how these different algorithms work. Additionally, there are (Code, Tests, and Runtime) folders you can explore.

## Code
This folder contains all my code for the different algorithms. I implemented the DFT, FFT, their inverses, and Python scripts to read and construct the frequency waves.

**Important:** My FFT function requires more signal inputs than the DFT function to remain accurate, and the IFFT function is currently producing the wrong output. However, the underlying structure of its function is correct.

To use the DFT and FFT functions, you must input the number of signal plots you are going to process. Then, you can input any numerical value that represents the y-axis value for your x-axis position. The input doesn't record the x-axis, so you can input plots from every second, tenth of a second, etc., as long as you are consistent with the same plotting distance.

The output will result in complex numbers, which provide information about the different frequencies that make up the signal you input.

The inverse functions, such as the IDFT and IFFT, simply swap the input and output of the DFT and FFT functions. So whatever your DFT outputted, you can plug that output into the IDFT, and it will return you the result of your DFT input.

To use the Python scripts to generate a graph from the algorithms, you must process a larger number of signals. For the DFT, 1000 signals are enough for graphs composed of a couple of frequencies. However, for the FFT, my code will require at least 10,000 signal inputs. The `time_graph.py` script will require you to input the number of signals you're processing and their values, just like the input for the DFT or FFT functions. It's recommended to create a script that outputs the signals you want to process. Examples can be found in the Tests folder. When you run the scripts, a .png file will be generated, which will display the input signal you are feeding into the function.

For `freq_domain_graph.py`, this script will take in the output of your DFT or FFT function and give you its frequency domain graph. This will require the output of your DFT or FFT functions. It's recommended to feed the output of these algorithms to a file and edit the top portion to remove the text and insert the number of signals you processed so that it's ready for the script to read. From here, the script will provide you with a graph of the frequencies that make up your signal.

## Tests
This folder provides examples of how the algorithms work and what their graphs look like. It runs different simulations for each test, representing the different sine waves you are generating. `tests_a` uses the DFT and FFT functions, while `tests_b` utilizes the inverses.

## Runtime
This folder gives you an idea of how much faster the FFT function is. There is a script that times the different algorithms for a range of input sizes. Additionally, there is a graph that visually demonstrates how much faster the FFT function is. The input doesn't matter as the function applies a constant-time equation to the signal. However, what matters is how the function iterates through its inputs, which is what causes the DFT to be much slower than the FFT function.
