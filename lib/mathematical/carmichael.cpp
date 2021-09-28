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
typedef long long ll;

long cycle;
long is_prime[N+1];
long prime[N];

ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    while(n>0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    return res;
}

bool judge(ll n){
    bool res = true;
    long p = 0;
    for(int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    
    for(int i = 2; i <=sqrt(n); i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j = 2 * i; j <= n; j+=i){
                is_prime[j] = false;
            }
            res = mod_pow(i, n, n) == i % n;
        }
        if(!res)break;
    }
    if(is_prime[n]) res = false;
    return res;
}

int main(){
    long n;
    //cin >> n;
    for(ll k = 3; k < 650000000000; k++){
        if(judge(k)) cout << k << endl;
    }
}