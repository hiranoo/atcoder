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
// const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n; cin >> n;
  int x, y; cin >> x >> y;
  vector<int> a(n), b(n);
  rep(i, 0, n-1) cin >> a[i] >> b[i];
  const int INF = 1000;
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(301, vector<int>(301, INF)));
  dp[0][0][0] = 0;
  rep(i, 0, n-1) rep(j, 0, 300) rep(k, 0, 300) {
    chmin(dp[i+1][j][k], dp[i][j][k]);
    chmin(dp[i+1][min(300, j+a[i])][min(300, k+b[i])], dp[i][j][k]+1);
  }

  int ans = INF;
  rep(j, x, 300) rep(k, y, 300) chmin(ans, dp[n][j][k]);
  if(ans < INF) cout << ans << endl;
  else cout << -1 << endl;
}