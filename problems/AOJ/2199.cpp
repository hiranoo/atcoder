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
  int n, m; cin >> n >> m;
  if(n==0 && m==0) return -1;
  vector<int> c(m);
  vector<int> x(n);
  rep(i, 0, m-1) cin >> c[i];
  rep(i, 0, n-1) cin >> x[i];

  vector< vector<ll> > dp(n+1, vector<ll>(256, INF));
  dp[0][128] = 0;
  rep(i, 0, n-1) rep(k, 0, 255) rep(j, 0, m-1) {
    int nk = k + c[j];
    if(nk > 255) nk = 255;
    if(nk < 0) nk = 0;
    dp[i+1][nk] = min(dp[i+1][nk], dp[i][k] + (ll)pow(nk - x[i], 2));
  }

  // cout << dp[1][132] << " " << dp[2][136] << endl;

  ll ans = INF;
  rep(j, 0, 255) ans = min(ans, dp[n][j]);
  cout << ans << endl;

  return 0;
}

int main() {
  while(1) {
    if(_main() == -1) break;
  }
}