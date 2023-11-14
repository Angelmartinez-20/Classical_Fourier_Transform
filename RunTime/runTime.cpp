#include <iostream>
#include <vector>
#include <chrono>
#include <complex>
#include <cmath>
#include "FT_functions.cpp"
using namespace std;

double dft_runtime(int n){
    vector<complex<double>> signals;
    double imag = 0.0;

    /* processing n number of signals plots */
    for(double i = 0; i < n; i ++){
        signals.push_back(complex<double>(i, imag));
    }
    /* record the time of how long DFT take for n signals */
    auto start = chrono::high_resolution_clock::now();
	DFT(signals);	
	auto end = chrono::high_resolution_clock::now();
    double elapsed_time = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    return elapsed_time;
}

double fft_runtime(int n){
    vector<complex<double>> signals;
    double imag = 0.0;
    
    /* processing n number of signals plots */
    for(double i = 0; i < n; i ++){
        signals.push_back(complex<double>(i, imag));
    }
    /* record the time of how long DFT take for n signals */
    auto start = chrono::high_resolution_clock::now();
	FFT(signals);		
	auto end = chrono::high_resolution_clock::now();
    double elapsed_time = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    return elapsed_time;
}

int main(){
    vector<int> num_signals = {100, 500, 1000, 5000, 10000, 25000, 50000};
    vector<double> dft_time;
    vector<double> fft_time;

    for(int i = 0; i < num_signals.size(); i++){
        dft_time.push_back(dft_runtime(num_signals[i]));
        fft_time.push_back(fft_runtime(num_signals[i]));
    }

    for(int i = 0; i < num_signals.size(); i++){
        cout << "To Process " << num_signals[i] << " number of plots in a signal, it took\n";
        cout << "DFT: " << dft_time[i] << " seconds\n";
        cout << "FFT: " << fft_time[i] << " seconds\n";
        cout << "========================================================================\n";
    }
}