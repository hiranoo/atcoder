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

// ll f(int i, int s, vector<vector<int>> &G, vector<vector<ll>> &dp, vector<vector<bool>> &flag) {
//   if(flag[i][s]) return dp[i][s];

//   for(auto)
// }

int main(){
  int n; cin >> n;
  vector<vector<int>> G(n, vector<int>(0));
  rep(i, 0, n-1) rep(j, 0, n-1) {
    int a; cin >> a;
    if(a>0) G[i].push_back(j);
  }

  vector<vector<ll>> dp(n, vector<ll>(1<<n, 0));
  // vector<vector<bool>> flag(n, vector<bool>(1<<n, 0));
  // ll ans = f(n-1, (1<<n)-1, G, dp, flag);
  for(auto j : G[0]) dp[0][1<<j] = 1;

  rep(i, 0, n-2) rep(S, 0, (1<<n)-1) {
    //if(bitset<22>(S).count() != i+1) continue;
    if(__builtin_popcount(S) != i+1) continue;
    for(auto j : G[i+1]) {     
      if((S>>j) & 1) continue;
      int T = S | (1 << j);
      
      dp[i+1][T] += dp[i][S];
      dp[i+1][T] %= MOD;
    }
  }
  cout << (dp[n-1][(1<<n)-1] + MOD) % MOD << endl;
}