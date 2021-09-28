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


int main() {
  int d, n; cin >> d >> n;
  vector<int> t(d);
  rep(i, 0, d-1) cin >> t[i];
  vector<int> c(n);
  vector<vector<int>> can(d, vector<int>(0));
  rep(j, 0, n-1) {
    int a, b, C; cin >> a >> b >> C;
    c[j] = C;
    rep(i, 0, d-1) if(a <= t[i] && t[i] <= b) can[i].push_back(j);
  }

  vector<vector<ll>> dp(d, vector<ll>(n, -INF));
  for(auto v : can[0]) dp[0][v] = 0;

  rep(i, 0, d-2){
    for(auto j : can[i+1]) {
      rep(k, 0, n-1) dp[i+1][j] = max(dp[i+1][j], dp[i][k] + abs(c[j] - c[k]));
    }
  }

  ll ans = 0;
  for(auto v : dp[d-1]) ans = max(ans, v);
  cout << ans << endl;
}