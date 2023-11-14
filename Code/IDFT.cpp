#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;


/* Gets Singal's Real# Info From User Input */
void get_signals(vector<complex<double>> &freq_domains) {
    double real, imag;
    char parse;
    int num_signals;

    cout << "How Many Frequence Domain signals Would You Like To Proccess: ";
    cin >> num_signals;
    cout << "Input Your Frequence Domains:\n";

    for(int i = 0; i < num_signals; i++){
        cin >> parse >> real >> parse >> imag >> parse;         // parses out "( , )"
        freq_domains.push_back(complex<double>(real, imag));
    }
}

/* Preforms IDFT on Signal To Get Freqince Domains*/
vector<complex<double>> idft(vector<complex<double>> &freq_domains) {
    vector<complex<double>> signals;
    double N = freq_domains.size();

    for(double n = 0; n < N; n++){
        complex<double> signal(0.0, 0.0);             
        for(double k = 0; k < N; k++){
            complex<double> i(0.0, 1.0);
            complex<double> w = exp(i * 2.0 * M_PI * k * n / N);
            signal += freq_domains[k] * w;              
        }
        signal.imag(round(signal.imag()));
        signal.real(signal.real()/N);
        signals.push_back(signal);
    }

    return signals;
}

/* Prints Frequence Domains as (Real#, Imaginary#) */
void print(vector<complex<double>> &signals) {
    cout << "===========================================\n";
    cout << "Time signal components:\n";
    for(int i = 0; i < signals.size(); i++){
        cout << signals[i].real() << endl;
    }
}

int main(){
    vector<complex<double>> freq_domains;
    vector<complex<double>> signals;  

    get_signals(freq_domains);
    signals = idft(freq_domains);
    print(signals);

    return 0;
}