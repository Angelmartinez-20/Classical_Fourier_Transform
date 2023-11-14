import matplotlib.pyplot as plt
import numpy as np

num_signals = int(input("How Many Signals Would You Like To Process: "))
time_step = 0.01  # 0.01 seconds (10 milliseconds)
time = [i * time_step for i in range(num_signals)]

signals = []
for i in range(num_signals):
    signals.append(float(input()))

# Creates plot graph
plt.plot(time, signals, linestyle='-')
plt.title('Time-Domain Signal')
plt.xlabel('Time in seconds')
plt.ylabel('Amplitude')

plt.savefig('time_graph.png')   # saves graph in png file
