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

    cout << res << endl;

    return 0;
}
