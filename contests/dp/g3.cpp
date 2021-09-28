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

int f(int v, vector<vector<int>> &to, vector<int> &dp) {
  if(dp[v] != -1) return dp[v];

  int fans = 0;
  for(auto nv : to[v]) {
    fans = max(fans, 1 + f(nv, to, dp));
  }
  return dp[v] = fans;
}

int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n, vector<int>(0));
  rep(i, 0, m-1) {
    int x, y; cin >> x >> y; x--; y--;
    to[x].push_back(y);
  }

  vector<int> dp(n, -1);
  
  rep(i, 0, n-1) f(i, to, dp);
  int ans = 0;
  rep(i, 0, n-1) ans = max(ans, dp[i]);
  cout << ans << endl;
}