#include <vector>
#include <random>
#include <algorithm>
using namespace std;

template<typename T, typename U>
void shuffle_together(vector<T>& a, vector<U>& b){
    vector<int> idx(a.size());
    for (int i = 0; i < (int)idx.size(); i++)
        idx[i] = i;

    random_device rd;
    mt19937 gen(rd());
    shuffle(idx.begin(), idx.end(), gen);

    vector<T> a_shuf(a.size());
    vector<U> b_shuf(b.size());

    for (int i = 0; i < (int)idx.size(); i++) {
        a_shuf[i] = a[idx[i]];
        b_shuf[i] = b[idx[i]];
    }

    a = move(a_shuf);
    b = move(b_shuf);
}