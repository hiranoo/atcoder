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
#define N 100000

long is_prime[N+1];
long prime[N];
bool judge(long n){
    bool res = true;
    for(long k = 2; k <= sqrt(n); k++){
        if(n%k==0){
            res = false;
            break;
        }
    }
    return res;
}

long count_prime(long n){
    long p = 0;
    for(int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j = 2 * i; j <= n; j+=i){
                is_prime[j] = false;
            }
        }
    }
    return p;
}

int main(){
    long n;
    cin >> n;
    if(judge(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
}