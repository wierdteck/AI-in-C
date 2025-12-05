#include <vector>
#include <random>
#include <algorithm>
using namespace std;

template<typename T, typename U>
void shuffle_together(vector<T>& a, vector<U>& b){
    vector<int> idx(data.size());
    for (int i = 0; i < (int)idx.size(); i++)
        idx[i] = i;

    random_device rd;
    mt19937 gen(rd());
    shuffle(idx.begin(), idx.end(), gen);

    vector<vector<double>> data_shuf(data.size());
    vector<double> ans_shuf(dataAns.size());

    for (int i = 0; i < (int)idx.size(); i++) {
        data_shuf[i] = data[idx[i]];
        ans_shuf[i] = dataAns[idx[i]];
    }

    data = move(data_shuf);
    dataAns = move(ans_shuf);
}