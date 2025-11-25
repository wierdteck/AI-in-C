
#ifndef LOSS_H
#define LOSS_H

#include <vector>


double MSE(const std::vector<double>& expected, const std::vector<double>& received);
double MAE(const std::vector<double>& expected, const std::vector<double>& received);
double BCE(const double& expected, double& received);
double CCE(const std::vector<double>& expected, const std::vector<double>& received);

#endif