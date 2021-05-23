#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i, n){
        cin >> l[i];
    }

    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if( (l[i]!=l[j] && l[j]!=l[k] && l[k]!=l[i]) && (l[i]+l[j]>l[k] && l[i]+l[k]>l[j] && l[j]+l[k]>l[i]) ){
                    cnt++;
                }
            }
        }
    }
    

    cout << cnt << endl;

    return 0;
}
