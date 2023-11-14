import matplotlib.pyplot as plt
import numpy as np

signal_plots = [100, 500, 1000, 5000, 10000, 25000, 50000]
dft_time = [0.00071901, 0.0179095, 0.0625028, 1.60742, 6.44574, 40.5506, 166.603]
fft_time = [4.7054e-05, 0.000225565, 0.000523724, 0.00330748, 0.00728806, 0.0198269, 0.0418298]

plt.plot(signal_plots, dft_time, linestyle='-', label='DFT', color='blue')
plt.plot(signal_plots, fft_time, linestyle='-', label='FFT', color='red')
plt.title('Runtime')
plt.xlabel('# Signal Plots')
plt.ylabel('Time in seconds')
plt.legend()  

plt.savefig('runTime.png')  