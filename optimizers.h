#include <vector>
#include <cmath>

using namespace std;

class SGD {
    private:
        double lr;
        
    public:
        SGD(double learning_rate = 0.01) : lr(learning_rate) {}
        
        void update(vector<double>& params, const vector<double>& grads) {
            for (size_t i = 0; i < params.size(); i++) {
                params[i] -= lr * grads[i];
            }
        }
};