#include <bits/stdc++.h>
#include <atcoder/all>
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

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int r, c, K; cin >> r >> c >> K;
  map<pii, ll> mp;
  rep(k, 0, K-1) {
    int i, j; ll v; cin >> i >> j >> v;
    mp[pii(i, j)] = v;
  }

  vector dp(r+1, vector<vector<ll>>(c+1, vector<ll>(4, 0)));
  rep(i, 1, r) rep(j, 1, c) {
    dp[i][j][1] = max(dp[i][j-1][1], dp[i-1][j][1]);
    if(mp.count(pii(i, j)) > 0) {
      ll v = mp[pii(i, j)];
      rep(k, 1, 3) chmax(dp[i][j][k], dp[i][j-1][k-1] + v);
      rep(k, 0, 3) chmax(dp[i][j][1], dp[i-1][j][k] + v);
    }
    rep(k, 0, 3) chmax(dp[i][j][k], dp[i][j-1][k]);
    rep(k, 0, 3) chmax(dp[i][j][0], dp[i-1][j][k]);
  }

  ll ans = 0;
  rep(k, 0, 3) chmax(ans, dp[r][c][k]);
  cout << ans << endl;
}