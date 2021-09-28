#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;

const ll M = 1000000007;

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    //cout << "a:" << a << " b:" << b << endl;
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

int main(){
  int n, m; cin >> n >> m;

  // パスカルの三角形
  /*
  vector<vector<int>> dp(1000000, vector<int>(1000000));
  dp[0][0] = 1;
  cout << "111" << endl;
  rep(i, 0, 100000-1) rep(j, 0, i){
    dp[i+1][j] += dp[i][j];
    dp[i+1][j+1] += dp[i][j];
  }

  cout << "5C2: " << dp[5][2] << endl;
  */

  vector<pii> prime_factorized(0);
  for(int i = 2; i*i <= m; i++){
    int idx = 0;
    while(m % i == 0){
      idx++;
      m /= i;
    }
    if(idx > 0) prime_factorized.push_back(pii(i, idx));
  }
  if(m > 1) prime_factorized.push_back(pii(m, 1));

  //for(auto v : prime_factorized) cout << v.first << " x " << v.second << endl;

  ll ans = 1;
  for(auto p : prime_factorized){
    ll k = p.second;

    //大した量ではないので，先にfax[i]とifax[i]を全て計算しておく
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }

    ll cc = comb(n-1 + k, k) % M; //p.second+1箇所から重複を許してn-1箇所選ぶ方法の数 = k+n C k
    ans *= cc;
    ans %= M;
  }
  
  cout << ans << endl;
}