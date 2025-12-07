#ifndef NNET_H
#define NNET_H

#include <vector>
#include <cmath>

using namespace std;

class NeuralNetwork {
    public:
        NeuralNetwork(const vector<int>& layers);
        vector<double> inference(const vector<double>& data);
        double Loss(const vector<double>& expected, const vector<double>& received);
        void backProp(const vector<double>& expected, const vector<double>& received, double learning_rate);

    private:
        vector<int> layers;
        vector<vector<vector<double>>> weights; // weights[layer][neuron][input]
        vector<vector<double>> biases; // biases[layer][neuron]

        double sigmoid(double x) {
            return 1.0 / (1.0 + exp(-x));
        }

        double sigmoid_derivative(double x) {
            double s = sigmoid(x);
            return s * (1 - s);
        }
};