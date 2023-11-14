import matplotlib.pyplot as plt
import numpy as np

N = int(input("How Many Complex #'s Would You Like To Process: "))

complex_numbers = []
for i in range(N):
    complex_str= input()                                            # formate (real, imag)
    real, imag = map(float, complex_str.strip('()').split(','))     # removes "( , )"
    complex_numbers.append(complex(real, imag))                     # only uses real and imag values


sampling_rate = 100 
frequencies = np.fft.fftfreq(N, 1 / sampling_rate)  # returns frequencies of input

positive_frequencies_indices = np.where(frequencies >= 0)           
positive_frequencies = frequencies[positive_frequencies_indices]
magnitudes = np.abs(complex_numbers)  

plt.figure(figsize=(10, 6))
plt.plot(positive_frequencies, magnitudes[positive_frequencies_indices])
plt.xlim(0,10)
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude')
plt.title('Frequency Domain Plot')
plt.grid(True)

plt.savefig('freq_domain.png')