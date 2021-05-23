#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

int extgcd(int a, int b, int& x, int& y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }else{
        int d = extgcd(b, a%b, y, x);
        y -= a/b * x;
        return d;
    }
}

int main(){
    int a, b, x, y;
    cin >> a >> b;
    x = 1; y = 1;
    int res = extgcd(a, b, x, y);
    cout << x << " " << y << endl;
}