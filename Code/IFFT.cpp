#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

/* Gets Freqince Domains Complex# Info From User Input */
void get_signals(vector<complex<double>> &freq_domain) {
    double real, imag;
    char parse;
    int num_signals;

    cout << "How Many Frequency Signals Would You Like To Proccess: ";
    cin >> num_signals;
    cout << "Input Your Frequencie:\n";

    for(int i = 0; i < num_signals; i++){
        cin >> parse >> real >> parse >> imag >> parse;         // parses out "( , )"
        freq_domain.push_back(complex<double>(real, imag));
    }
}

/* Preforms inverse FFT on Freqince Domains To Get Signals */
vector<std::complex<double>> iFFT(vector<std::complex<double>> &freq_domain) {
    int N = freq_domain.size();
    if (N == 1) {return freq_domain;}

    /* split input array in half */ 
    std::vector<std::complex<double>> even(N / 2);
    std::vector<std::complex<double>> odd(N / 2);
    for (int i = 0; i < N / 2; i++) {
        even[i] = freq_domain[2 * i];
        odd[i] = freq_domain[2 * i + 1];
    }

    /* recursively call iFFT on split arrays */ 
    std::vector<std::complex<double>> even_ifft = iFFT(even);
    std::vector<std::complex<double>> odd_ifft = iFFT(odd);

    /* combine arrays & implment iFFT */ 
    vector<std::complex<double>> signals(N);
    for (double i = 0; i < N / 2; i++) {
        double n_double = N;
        complex<double> imag(0.0, 1.0);
        complex<double> w = exp(-2.0 * imag * M_PI * i / n_double);
        signals[i] = (even_ifft[i] + w * odd_ifft[i]) * (1/n_double);
        signals[i + N / 2] = (even_ifft[i] - w * odd_ifft[i])  * (1/n_double);
    }

    return signals;
}

/* Prints signals as Real# */
void print(vector<complex<double>> &signals) {
    cout << "===========================================\n";
    cout << "Signal Components:\n";
    for(int i = 0; i < signals.size(); i++){
        cout << signals[i].real() << endl;
    }
}

int main(){
    vector<complex<double>> freq_domain;
    vector<complex<double>> signals;
    get_signals(freq_domain);
    signals = iFFT(freq_domain);
    print(signals);    
    return 0;
}