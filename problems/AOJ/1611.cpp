#include <bits/stdc++.h>
// #include <atcoder/segtree>
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
const ll INF = 1e18;

int _main() {
  int n; cin >> n;
  if(n == 0) return -1;
  vector<int> w(n);
  rep(i, 0, n-1) cin >> w[i];

  vector< vector<int> > dp(n, vector<int>(n, -1));
  rep(i, 0, n-1) dp[i][i] = 0;
  rep(i, 0, n-2) {
    dp[i][i+1] = 0;
    if(abs(w[i]-w[i+1]) <= 1) dp[i][i+1] = 2;
  }

  rep(jj, 2, n) rep(i, 0, n-1) {
    int j = i + jj;
    if(j >= n) continue;
    if(dp[i][j] != -1) continue;
    if(abs(w[i]-w[j]) <= 1 && dp[i+1][j-1] == j-i-1) dp[i][j] = dp[i+1][j-1] + 2;
    rep(k, i, j-1) dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
    // cout << i << " " << j << " " << dp[i][j] << endl;
  }

  cout << dp[0][n-1] << endl;
  return 0;
}

int main() {
  while(1) {
    if(_main() == -1) break;
  }
}