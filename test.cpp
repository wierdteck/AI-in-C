#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "perceptron.h"
#include "usefulFuncs.h"
#include "optimizers.h"
using namespace std;

int main(){
    //testing 
    vector<vector<double>> data = {{0, 0},{0, 1},{1, 0},{1, 1}};
    vector<double> dataAns = {0, 1, 1, 1};
    Perceptron model = Perceptron(2);
    double lr = 0.01;
    for(int epoch = 0; epoch < 1000; epoch++){
        for(int i = 0; i < data.size(); i++){
            model.backProp(data[i], dataAns[i], lr);
        }
        if(epoch % 100 == 0){
            double totalLoss = 0.0;
            for(int i = 0; i < data.size(); i++){
                totalLoss += model.Loss(data[i], dataAns[i]);
            }
            cout << "Epoch " << epoch << ", Loss: " << totalLoss / data.size() << endl;
        }
    }
}