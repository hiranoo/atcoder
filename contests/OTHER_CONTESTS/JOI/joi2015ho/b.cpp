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


ll f(int i, int j, vector<ll> &a, vector<vector<ll>> &dp) {
  if(dp[i][j] != -1) return dp[i][j];
  
  ll fans = 0;
  if(a[i] > a[j]) {
    fans = max(fans, a[i+1] + f(i+2, j, a, dp));
    fans = max(fans, a[j] + f(i+1, j-1, a, dp));
  }
  if(a[i] < a[j]) {
    fans = max(fans, a[i] + f(i+1, j-1, a, dp));
    fans = max(fans, a[j-1] + f(i, j-2, a, dp));
  }

  // cout << i << " " << j << " " << fans << endl;
  return dp[i][j] = fans;
}

int main() {
  int n; cin >> n;
  vector<ll> a(2*n);
  rep(i, 0, n-1) {
    int c; cin >> c;
    a[i] = a[i+n] = c;
  }

  vector<vector<ll>> dp(2*n, vector<ll>(2*n, -1));
  rep(i, 0, 2*n-1) dp[i][i] = 0;
  rep(i, 0, 2*n-2) dp[i][i+1] = min(a[i], a[i+1]);

  ll ans = 0;
  rep(i, 0, n-1) ans = max(ans, a[i] + f(i+1, i+n-1, a, dp));
  cout << ans << endl;
}