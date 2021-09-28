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
#include <atcoder/modint>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using namespace atcoder;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
using mint = modint1000000007;
const ll MAX_N = 33;

struct Matrix{
  ll MOD = 1000000007;
  int sz;
  vector< vector<ll> > x;
  
  Matrix (int n) : sz(n), x(n, vector<ll>(n, 0)) {}

  inline const vector<ll> &operator[](int k) const {
    return (x.at(k));
  }

  inline vector<ll> &operator[](int k) {
    return (x.at(k));
  }
  
  Matrix operator* (Matrix &b){
    Matrix mul(sz);
    rep(i, 0, sz-1) rep(j, 0, sz-1) rep(k, 0, sz-1) {
      mul.x[i][j] += x[i][k] * b.x[k][j];
      mul.x[i][j] %= MOD;
    }
    return mul;
  }

  Matrix powers(ll n){
    vector<Matrix> p(63, Matrix(sz));
    Matrix res(sz); rep(i, 0, sz-1) res.x[i][i] = 1;

    p[0].x = x;
    rep(i, 1, 62) p[i] = p[i-1] * p[i-1];
    
    rep(i, 0, 62){
      if(n & 1LL << i) res = res * p[i];
    }

    return res;
  }
};


long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 63; i++) {
		if ((b & (1LL << i)) != 0) {
			p *= q;
			p %= m;
		}
		q *= q;
		q %= m;
	}
	return p;
}


int main(){
  ll N; int B, K;
  cin >> N >> B >> K;
  vector<int> c(K);
  rep(i, 0, K-1) cin >> c[i];

  /*
  vector<vector<int>> dp(N+5, vector<int>(B, 0));
  dp[0][0] = 1;
  rep(i, 0, N){
    rep(j, 0, B-1){
      rep(k, 0, K-1){
        int nj = (10*j + c[k]) % B;
        dp[i+1][nj] += dp[i][j];
      }
    }
  }
  */

  // DP[i][j]: 2^i 桁目がj (modB)
  vector<vector<ll>> DP(65, vector<ll>(B, 0));
  for(auto v : c) DP[0][v%B]++;

  vector<ll> power10(65); 
  // power10[0] = 10LL;
  // rep(i, 0, 61) power10[i+1] = (power10[i] * power10[i])%MOD;
  rep(i, 0, 63) power10[i] = modpow(10LL, (1LL << i), B);
  rep(i, 0, 62) {
    rep(j, 0, B-1){
      rep(k, 0, B-1){
        int nj = (power10[i]*j + k)%B;
        DP[i+1][nj] += (DP[i][j] * DP[i][k]) %MOD;
        DP[i+1][nj] %= MOD;
      }
    }
  }

  vector<vector<ll>> ans(63, vector<ll>(B, 0));
  ans[0][0] = 1;
  for(int i = 0; i <= 61; i++) {
    if(N & 1LL << i){
      for(int j = 0; j < B; j++){
        for(int k = 0; k < B; k++){
          int nj = (power10[i] * j + k) % B;
          ans[i+1][nj] += (ans[i][j] * DP[i][k]) % MOD;
          ans[i+1][nj] %= MOD;
        }
      }
    }else{
      rep(j, 0, B-1) ans[i+1][j] = ans[i][j];
    }
  }

  cout << ans[61][0] << endl;

  /*
  Matrix A(B);
  rep(j, 0, B-1) rep(k, 0, K-1) {
    int nj = (10 * j + c[k]) % B;
    A.x[nj][j]++;
  }

  Matrix res = A.powers(N);

  cout << res.x[0][0] << endl;
  */
}