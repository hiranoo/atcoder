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
  vector<int> a(n), b(n), c(n);
  rep(i, 0, n-1) cin >> a[i] >> b[i] >> c[i];
  vector<vector<int>> dp(n+1, vector<int>(3));
  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  rep(i, 1, n) {
    dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i-1];
    dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i-1];
    dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i-1];
  }
  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}