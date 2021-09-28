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
const int MAX_N = 100005;


int main () {
  int n; cin >> n;
  vector<double> p(n+1); p[0] = 0;
  rep(i, 1, n) cin >> p[i];

  vector<vector<double>> dp(n+1, vector<double>(n+1, 0));
  dp[1][0] = 1 - p[1];
  dp[1][1] = p[1];

  for(int i = 2; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      if(j == 0) dp[i][j] = (1 - p[i]) * dp[i-1][j];
      else dp[i][j] = (1 - p[i]) * dp[i-1][j] + p[i] * dp[i-1][j-1];
    }
  }

  double head = 0;
  for(int j = 0; j <= n; j++) {
    if(2*j > n) head += dp[n][j];
  }

  cout << fixed << setprecision(11) << head << endl;
}