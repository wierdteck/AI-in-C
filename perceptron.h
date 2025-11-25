#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>

class Perceptron{
    public:
        Perceptron(int s);
        double inference(const std::vector<double>& data);
        double test(const std::vector<double> &data, const double &y);
        double Loss(const std::vector<double> &data, const double &y);
        void backProp(const std::vector<double> &data, const double &y, const double& a);
        void Print();

    private:
        int size;
        std::vector<double> weights;
        double bias;
        
        double sigmoid(double x);
};

#endif