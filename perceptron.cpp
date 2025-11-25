#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Perceptron{
    public:
        Perceptron(int s);
        double inference(const vector<int>& data);
        double test(const vector<int> &data, const int &y);

        void Print(){
            for(int i = 0; i < size; i++){
                cout << "The weight and bias for this nueron is: " << weights[i] << ", " << biases[i] << endl;
            }
        }
    private:
        int size;
        vector<double> weights;
        vector<double> biases;
};

Perceptron::Perceptron(int s){
    size = s;

    //randomly assign the weights and biases
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(-1.0, 1.0);
    for(int i = 0; i < s; i++){
        weights.push_back(dist(gen));
        biases.push_back(dist(gen));
    }
}

double Perceptron::inference(const vector<int> &data){
    (void)data;
    double ret = 0.0;
    for(int i = 0; i < size; i++){
        ret+=data[i]*weights[i]+biases[i];
    }
    return ret;
}

double Perceptron::test(const vector<int> &data, const int &y){
    return y-inference(data);
}

int main(){
    return 0;
}