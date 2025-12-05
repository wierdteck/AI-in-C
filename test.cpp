#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "perceptron.h"
#include "usefulFuncs.h"
using namespace std;

int main(){
    //testing 
    vector<vector<double>> data;
    vector<double> dataAns;
    for(double d = 0.0; d <= 1.0; d+=0.03125){
        for(double d2 = 0.0; d2 <= 1.0; d2+=0.03125){
            data.push_back({d, d2});
            double ans = (d2 > d) ? 1.0 : 0.0;
            dataAns.push_back(ans);
        }
    }
    Perceptron model = Perceptron(2);
    
}