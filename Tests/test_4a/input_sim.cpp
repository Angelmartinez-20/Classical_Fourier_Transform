#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

/* 2Hz + 4Hz wave simulator */
int main(){
    cout << 10000 << endl;
    for(double i = 0.0; i < 100; i += 0.01){
        cout << sin(2* M_PI * 2 * i) + sin(2* M_PI * 4 * i) << endl;
    }
}