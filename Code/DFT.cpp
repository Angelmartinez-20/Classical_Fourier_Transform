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

/* Preforms DFT on Signal To Get Freqince Domains*/
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

/* Prints Frequence Domains as (Real#, Imaginary#) */
void print(vector<complex<double>> &freq_domains) {
    cout << "===========================================\n";
    cout << "Frequency Domain Components:\n";
    for(int i = 0; i < freq_domains.size(); i++){
        cout << freq_domains[i] << endl;
    }
}

int main(){
    vector<complex<double>> signals;
    vector<complex<double>> freq_domains;

    get_signals(signals);
    freq_domains = DFT(signals);
    print(freq_domains);

    return 0;
}