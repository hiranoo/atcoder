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

ll f(vector<int> &a, vector<vector<ll>> &dp, vector<vector<bool>> &flag, int s, int t) {
  if(flag[s][t]) return dp[s][t];
  ll fans = max(a[s] - f(a, dp, flag, s+1, t), a[t] - f(a, dp, flag, s, t-1));
  flag[s][t] = true;
  return dp[s][t] = fans;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  vector<vector<ll>> dp(n, vector<ll>(n));
  vector<vector<bool>> flag(n, vector<bool>(n, false));
  rep(i, 0, n-1) {
    dp[i][i] = a[i];
    flag[i][i] = true;
  }
  
  ll ans = f(a, dp, flag, 0, n-1);
  cout << ans << endl;
}