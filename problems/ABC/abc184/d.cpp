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

int main() {
  int a, b, c; cin >> a >> b >> c;
  vector< vector< vector<double> > > dp(101, vector<vector<double>>(101, vector<double>(101, 0)));
  //dp[a][b][c] = 1;

  rep(i, a, 99) rep(j, b, 99) rep(k, c, 99) {
    dp[i+1][j][k] += dp[i][j][k] + (double)i / (i+j+k);
    dp[i][j+1][k] += dp[i][j][k] + (double)j / (i+j+k);
    dp[i][j][k+1] += dp[i][j][k] + (double)k / (i+j+k);
  }

  rep(i, a, 100) rep(j, b, 100) rep(k, c, 100) {
    if(dp[i][j][k] != 0) {
      printf("%d, %d, %d: ", i, j, k); 
      cout << dp[i][j][k] << endl;
    }
  }
  double ans = 0;
  rep(j, b, 99) rep(k, c, 99) ans += dp[100][j][k];
  rep(i, a, 99) rep(k, c, 99) ans += dp[i][100][k];
  rep(j, b, 99) rep(k, c, 99) ans += dp[100][j][k];

  cout << fixed << setprecision(8) << ans << endl;
}