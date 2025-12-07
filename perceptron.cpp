#include "Loss.h"
#include "perceptron.h"
#include <iostream>
#include <vector>
#include <random>
using namespace std;

Perceptron::Perceptron(int s){
    size = s;

    //randomly assign the weights and biases
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(-1.0, 1.0);
    for(int i = 0; i < size; i++){
        weights.push_back(dist(gen));
    }
    bias = dist(gen);
}

double Perceptron::inference(const vector<double> &data){
    double ret = bias;
    for(int i = 0; i < size; i++){
        ret+=data[i]*weights[i];
    }
    return sigmoid(ret);
}

double Perceptron::test(const vector<double>& data, const double& y){
    return y-inference(data);
}
double Perceptron::Loss(const vector<double>& data, const double& y){
    return BCE(y, inference(data));
}
void Perceptron::backProp(const vector<double>& data, const double& y, const double& a){
    double dldf = inference(data) - y;
    for(int i = 0; i < size; i++){
        weights[i] -= a*data[i]*dldf;
    }
    bias -= a*dldf;
}