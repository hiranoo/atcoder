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
  int n; cin >> n;
  vector<vector<int>> G(n, vector<int>(0));
  rep(i, 0, n-1) {
    rep(j, 0, n-1) {
      int a; cin >> a;
      if(a) G[i].push_back(j);
    }
  }

  vector<vector<ll>> dp(n, vector<ll>(1LL<<n+1, 0));
  for(auto j : G[0]) {
    dp[0][1LL<<j] = 1;
  }

  rep(i, 0, n-2) {
    rep(s, 0, (1LL<<n)-1) {
      // cout << bitset<3>(s) << " : " << bitset<3>(s).count() << endl;
      if(bitset<24>(s).count() != i+1) continue;
      for(auto k : G[i+1]) if( !(s & 1LL << k) ) {
        // cout << "dp[" << i+1 << "][" << bitset<3>(s | 1 << k) << "] += dp[" << i << "][" << bitset<3>(s) << "] : ";
        // cout << dp[i+1][s | 1<<k] << " += " << dp[i][s] << endl;
        dp[i+1][s | 1<<k] += dp[i][s];
        dp[i+1][s | 1<<k] %= MOD;
      }
    }
    // cout << endl;
  }

  cout << (dp[n-1][(1LL<<n)-1] + MOD) % MOD << endl;
}