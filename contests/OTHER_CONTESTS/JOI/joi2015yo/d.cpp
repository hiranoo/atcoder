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
  int n, m; cin >> n >> m;
  vector<int> d(n);
  rep(i, 0, n-1) cin >> d[i];
  vector<int> c(m);
  rep(i, 0, m-1) cin >> c[i];

  vector<vector<ll>> dp(m+5, vector<ll>(n+5, INF));

  rep(i, 0, m) dp[i][0] = 0;
  rep(i, 0, m-1) rep(j, 0, n-1) dp[i+1][j+1] = min(dp[i][j+1], dp[i][j] + c[i]*d[j]);

  ll ans = INF;
  rep(i, 0, m) ans = min(ans, dp[i][n]);
  cout << ans << endl;

  // rep(i, 0, m) {
  //   cout << i << "日目の始まり： ";
  //   rep(j, 0, n) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}