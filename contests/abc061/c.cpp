#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

int main(){
    string str;
    cin >> str;
    int n = str.size();
    int arr[n];
    
    rep(i, 0, n-1){
        int e = str[i] - '0';
        arr[i] = e;
    }   

    long sum = 0;
    // position map of '+'
    for(long msk = 0; msk <= ((1 << (n-1)) - 1); msk++){
        long buff = arr[0];
        for(int i = 0; i <= (n-2); i++){
            // +
            if( msk & (1 << (n-2-i)) ){
                sum += buff;
                buff = arr[i+1];
                if(i == n-2){
                    sum += buff;
                }
            // none
            }else{
                buff = 10 * buff + arr[i+1];
                if(i == n-2){
                    sum += buff;
                }
            }
        }
        
    }
    if(n==1){
        sum = arr[0];
    }

    cout << sum << endl;

    return 0;
}
