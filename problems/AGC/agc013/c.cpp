#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
    long n, L, T;
    cin >> n >> L >> T;
    vector<long> x(n), w(n);
    rep(i, n){
        cin >> x[i] >> w[i];
        if(w[i]==2){w[i]=-1;}
    }

    long long gap = 0;
    rep(i,n){
        long long p = x[i] + w[i]*T;
        gap += p/L;
        if(p%L < 0) gap-=1;
        x[i] = ( p % L + L ) % L;
    }

    sort(x.begin(), x.end());

    gap = (gap%n + n) %n;
    for(int i = gap; i < n; i++){    
        cout << x[i] << endl;
    }
    for(int i = 0; i < gap; i++){
        cout << x[i] << endl;
    }

    return 0;
}
