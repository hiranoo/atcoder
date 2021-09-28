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
  vector<int> c(m);
  rep(i, 0, m-1) cin >> c[i];

  vector< vector<int> > dp(m+1, vector<int>(n+1, 100100100));
  rep(i, 0, m) dp[i][0] = 0;
  rep(i, 0, m-1) rep(j, 0, n) {
    if(j < c[i]) dp[i+1][j] = dp[i][j];
    else dp[i+1][j] = min(dp[i][j], dp[i+1][j-c[i]] + 1);
  }

  cout << dp[m][n] << endl;
}
