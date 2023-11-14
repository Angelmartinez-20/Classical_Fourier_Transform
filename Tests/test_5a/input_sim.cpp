#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

/* 1Hz + 3Hz + 4Hz + 7Hz wave simulator */
int main(){
    cout << 10000 << endl;
    for(double i = 0.0; i < 100; i += 0.01){
        cout << sin(2* M_PI * 1 * i) + sin(2* M_PI * 3 * i) + sin(2* M_PI * 4 * i) + sin(2* M_PI * 7 * i) << endl;
    }
}