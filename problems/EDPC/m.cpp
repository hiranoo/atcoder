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
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;

int main(){
  int n, K; cin >> n >> K;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];
  vector<vector<ll>> dp(n, vector<ll>(K+1, 0));
  rep(i, 0, n-1) dp[i][0] = 1;
  rep(i, 0, a[0]) dp[0][i] = 1;

  rep(i, 1, n-1) rep(j, 0, K) {
    ll ret = dp[i-1][j];
    if(j > 0) ret += dp[i][j-1];
    if(a[i] > 0 && j-a[i]-1 >= 0) ret -= dp[i-1][j-a[i]-1];
    dp[i][j] = ret % MOD;
  }

  cout << (dp[n-1][K] + MOD) % MOD << endl;
}