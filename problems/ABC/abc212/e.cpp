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
const ll MOD = 998244353;
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> to(n);
  rep(i, 0, m-1) {
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v);
    to[v].push_back(u);
  }

  vector dp(k+1, vector<ll>(n, 0));
  dp[0][0] = 1;
  rep(i, 1, k) {
    ll tot = 0;
    rep(j, 0, n-1) tot += dp[i-1][j], tot %= MOD;
    rep(j, 0, n-1) {
      dp[i][j] = tot - dp[i-1][j], dp[i][j] %= MOD;
      for(auto pre : to[j]) dp[i][j] -= dp[i-1][pre], dp[i][j] %= MOD;
    }
  }

  cout << (dp[k][0] + MOD) % MOD << endl;
}