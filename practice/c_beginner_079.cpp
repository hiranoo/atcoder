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

char out(int msk, int i){
    if(msk & (1 << (2-i))){
        return '+';
    }else{
        return '-';
    }
}

int main(){
    string s;
    cin >> s;
    int a[4];
    rep(i, 0, 3){
        a[i] = (int)(s[i] - '0');
    }

    for(int msk = 0; msk < (1 << 3); msk++){
        int sum = a[0];
        for(int i = 0; i < 3; i++){
            int op = (msk & (1 << (2-i)));
            if(op){op = 1;}
            else{op = -1;}
            sum += a[i+1] * op;
        }
        if(sum == 7){
            for(int i = 0; i < 3; i++){
                cout << a[i] << out(msk, i);
            }
            cout << a[3] << "=7" << endl;
            return 0;
        }

    }
    return 0;
}