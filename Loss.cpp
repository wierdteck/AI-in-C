/*
| || 
|| |_
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Loss.h"
using namespace std;
double MSE(const vector<double>& expected, const vector<double>& received){ //mean-squared error
    if (expected.size() != received.size()) {
        throw std::invalid_argument("Vectors must be the same size");
    }
    double ret = 0.0;
    int size = expected.size();
    for(int i = 0; i < size; i++){
        ret+=pow(expected[i]-received[i], 2);
    }
    return ret/size;
}
double MAE(const vector<double>& expected, const vector<double>& received){ //mean-absolute error
    if (expected.size() != received.size()) {
        throw std::invalid_argument("Vectors must be the same size");
    }
    double ret = 0.0;
    int size = expected.size();
    for(int i = 0; i < size; i++){
        ret+=fabs(expected[i]-received[i]);
    }
    return ret/=size;
}
double BCE(const double& expected, double& received){ //binary cross entropy (expected and received are on the unit interval)
    received = clamp(received, 1e-15, 1 - 1e-15);   
    return -(expected*log(received) + (1-expected)*log(1-received));
}

double CCE(const vector<double>& expected, const vector<double>& received){ // categorical loss entropy
    double ret = 0.0;
    double eps = 1e-15;
    for (size_t i = 0; i < expected.size(); i++) {
        double r = std::clamp(received[i], eps, 1 - eps);
        ret += expected[i] * log(r);
    }
    return -ret;
}
int main(){
    return 0;
}