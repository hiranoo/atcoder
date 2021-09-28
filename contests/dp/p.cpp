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

pll f(int v, vector<vector<int>> &G, vector<bool> &visited, vector<bool> &flag, vector<pll> &dp) {
  visited[v] = true;
  if(flag[v]) return dp[v];
  
  ll res_b = 1, res_w = 1;
  for(auto ch : G[v]) {
    if(visited[ch]) continue;
    res_b *= f(ch, G, visited, flag, dp).second;
    res_w *= f(ch, G, visited, flag, dp).first + f(ch, G, visited, flag, dp).second;
    res_b %= MOD; res_w %= MOD;
  }
  
  flag[v] = true;
  return dp[v] = pll(res_b, res_w);
}

// void f(int v, vector<vector<int>> &G, vector<bool> &visited, vector<bool> &flag, vector<pll> &dp) {
//   visited[v] = true;
//   if(flag[v]) return;
  
//   dp[v] = pll(1, 1);
//   for(auto ch : G[v]) {
//     if(visited[ch]) continue;
//     f(ch, G, visited, flag, dp);
//     dp[v].first *= dp[ch].second;
//     dp[v].second *= dp[ch].first+dp[ch].second;
//     dp[v].first %= MOD;
//     dp[v].second %= MOD;
//   }
  
//   flag[v] = true;
// }

int main(){
  int n; cin >> n;
  vector<vector<int>> G(n, vector<int>(0));
  rep(i, 0, n-2) {
    int x, y; cin >> x >> y; x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  vector<pll> dp(n);
  vector<bool> flag(n, false), visited(n, false);

  f(0, G, visited, flag, dp);
  ll ans = (dp[0].first + dp[0].second) % MOD;

  cout << (ans + MOD) % MOD << endl;
}