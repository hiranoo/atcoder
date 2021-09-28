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

int lcs(string x, string y) {
  int n = x.size(), m = y.size();
  vector< vector<int> > dp(n+1, vector<int>(m+1));
  dp[0][0] = 0;
  rep(i, 0, n-1) rep(j, 0, m-1) {
    if(x[i] == y[j]) dp[i+1][j+1] = dp[i][j] + 1;
    else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
  }
  return dp[n][m];
}

int main() {
  int q; cin >> q;
  rep(i, 0, q-1) {
    string x, y; cin >> x >> y;
    cout << lcs(x, y) << endl;
  }
}
 
