#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

/* Gets Singal's Real# Info From User Input */
void get_signals(vector<complex<double>> &signals) {
    double real, imag = 0.0;
    int num_signals;

    cout << "How Many Signals Would You Like To Proccess: ";
    cin >> num_signals;
    cout << "Input Your Singals Frequencies:\n";

    for(int i = 0; i < num_signals; i++){
        cin >> real;
        signals.push_back(complex<double>(real, imag));
    }
}

/* Preforms FFT on Signal To Get Freqince Domains */
vector<complex<double>> FFT(vector<complex<double>> &signals) {
    int N = signals.size();
    if (N == 1) {return signals;}

    /* split input array in half */ 
    vector<complex<double>> even(N / 2);
    vector<complex<double>> odd(N / 2);
    for (int i = 0; i < N / 2; i++) {
        even[i] = signals[2 * i];
        odd[i] = signals[2 * i + 1];
    }

    /* recursively call FFT on split arrays */ 
    vector<complex<double>> even_fft = FFT(even);
    vector<complex<double>> odd_fft = FFT(odd);

    /* combine arrays & implment FFT */ 
    vector<complex<double>> freq_domain(N);
    for (double i = 0; i < N / 2; i++) {
        double n_double = N;
        complex<double> imag(0.0, 1.0);
        complex<double> w = exp(-2.0 * imag * M_PI * i / n_double);
        freq_domain[i] = even_fft[i] + w * odd_fft[i];
        freq_domain[i + N / 2] = even_fft[i] - w * odd_fft[i];
    }

    return freq_domain;
}

/* Prints Frequence Domains as (Real#, Imaginary#) */
void print(vector<complex<double>> &freq_domains) {
    cout << "===========================================\n";
    cout << "Frequency Domain Components:\n";
    for(int i = 0; i < freq_domains.size(); i++){
        cout <<  freq_domains[i] << endl;
    }
}

int main(){
    vector<complex<double>> signals;
    vector<complex<double>> freq_domains;
    get_signals(signals);
    freq_domains = FFT(signals);
    print(freq_domains);    
    return 0;
}