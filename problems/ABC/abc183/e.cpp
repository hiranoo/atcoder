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
const ll INF = 1e18;
// const int INF = 1001001001;

int main() {
  int h, w; cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h-1) cin >> a[i];

  vector<vector<ll>> dp(h, vector<ll>(w, 0));
  vector<vector<ll>> x(h, vector<ll>(w, 0));
  vector<vector<ll>> y(h, vector<ll>(w, 0));
  vector<vector<ll>> xy(h, vector<ll>(w, 0));
  dp[0][0] = 1;
  x[0][0] = y[0][0] = xy[0][0] = 1;
    rep(i, 0, h-1) rep(j, 0, w-1) {
    if(i == 0 && j == 0) continue;
    if(a[i][j] == '#') continue;
    if(j) x[i][j] += x[i][j-1];
    if(i) y[i][j] += x[i-1][j];
    if(i && j) xy[i][j] += x[i-1][j-1];
    x[i][j] %= MOD;
    y[i][j] %= MOD;
    xy[i][j] %= MOD;
    dp[i][j] += x[i][j];
    dp[i][j] += y[i][j];
    dp[i][j] += xy[i][j];
    dp[i][j] %= MOD;
    x[i][j] += dp[i][j];
    y[i][j] += dp[i][j];
    xy[i][j] += dp[i][j];
    x[i][j] %= MOD;
    y[i][j] %= MOD;
    xy[i][j] %= MOD;
  }
  
  // rep(i, 0, h-1) rep(j, 0, w-1) if(a[i][j] =='.') {
  //   rep(k, 1, i) {
  //     if(a[i-k][j] == '#') break;
  //     dp[i][j] += dp[i-k][j];
  //     dp[i][j] %= MOD;
  //   }
  //   rep(k, 1, j) {
  //     if(a[i][j-k] == '#') break;
  //     dp[i][j] += dp[i][j-k];
  //     dp[i][j] %= MOD;
  //   }
  //   rep(k, 1, min(i, j)) {
  //     if(a[i-k][j-k] == '#') break;
  //     dp[i][j] += dp[i-k][j-k];
  //     dp[i][j] %= MOD;
  //   }
  // }

  cout << (dp[h-1][w-1] + MOD) % MOD << endl;
}