#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n){
        cin >> x[i] >> y[i];
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            max = fmax(max, pow(x[i]-x[j], 2.0) + pow(y[i]-y[j], 2.0));
        }
    }

    double res = sqrt(max);
    cout << res << endl;

    return 0;
}