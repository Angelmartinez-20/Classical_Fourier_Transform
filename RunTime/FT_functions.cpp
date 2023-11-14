#include <iostream>
#include <vector>
#include <chrono>
#include <complex>
#include <cmath>
using namespace std;

vector<complex<double>> DFT(vector<complex<double>> &signals) {
    vector<complex<double>> freq_domains;
    double N = signals.size();

    for(double n = 0; n < N; n++) {
        complex<double> freq(0.0, 0.0);             
        for(double k = 0; k < N; k++) {
            complex<double> i(0.0, 1.0);
            complex<double> w = exp(-i * 2.0 * M_PI * k * n / N);
            freq += signals[k] * w;              
        }
        freq_domains.push_back(freq);
    }

    return freq_domains;
}

vector<complex<double>> FFT(vector<complex<double>> &signals) {
    int n = signals.size();
    if (n == 1) {return vector<complex<double>>{signals[0]};}

    /* split input array in half */ 
    vector<complex<double>> even(n / 2);
    vector<complex<double>> odd(n / 2);
    for (int i = 0; i < n / 2; i++) {
        even[i] = signals[2 * i];
        odd[i] = signals[2 * i + 1];
    }

    /* recursively call FFT on split arrays */ 
    vector<complex<double>> even_fft = FFT(even);
    vector<complex<double>> odd_fft = FFT(odd);

    /* combine arrays & implment FFT */ 
    vector<complex<double>> freq_domain(n);
    for (double i = 0; i < n / 2; i++) {
        double n_double = n;
        complex<double> im(0.0, 1.0);
        complex<double> w = exp(-2.0 * im * M_PI * i / n_double);
        freq_domain[i] = even_fft[i] + w * odd_fft[i];
        freq_domain[i + n / 2] = even_fft[i] - w * odd_fft[i];
    }

    return freq_domain;
}