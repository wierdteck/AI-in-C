#include "Loss.h"
#include "perceptron.h"
#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Perceptron{
    public:
        Perceptron(int s);
        double inference(const vector<double>& data);
        double test(const vector<double> &data, const double &y);
        double Loss(const vector<double> &data, const double &y);
        double backProp(const vector<double> &data, const double &y, const double& a);

        void Print(){
            for(int i = 0; i < size; i++){
                cout << "The weight for this nueron is: " << weights[i] << endl;
            }
            cout << "The bias is: " << bias << endl; 
        }
    private:
        int size;
        vector<double> weights;
        double bias;
        double sigmoid(double x){
            return 1.0 / (1.0 + exp(-x));
        }
};

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
double Perceptron::backProp(const vector<double>& data, const double& y, const double& a){
    double dldf = inference(data) - y;
    for(int i = 0; i < size; i++){
        weights[i] -= a*data[i]*dldf;
    }
    bias -= a*dldf;
}

int main(){
    return 0;
}