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

string color = "RBW";

ll cost(vector<string> &s, int i, int j) {
  ll ans = 5;
  rep(k, 0, 4) if(s[k][i-1] == color[j]) ans--;
  return ans;
}

int main() {
  int n; cin >> n;
  vector<string> s(5);
  rep(i, 0, 4) cin >> s[i];

  vector<vector<ll>> dp(n+1, vector<ll>(3, INF));
  rep(j, 0, 2) dp[0][j] = 0;

  rep(i, 0, n-1) rep(j, 0, 2) rep(k, 0, 2) if(j != k) {
    // printf("%d, %d, %d\n", i, j, k);
    dp[i+1][j] = min(dp[i+1][j], dp[i][k] + cost(s, i+1, j));
  }



  ll ans = INF;
  rep(j, 0, 2) ans = min(ans, dp[n][j]);
  cout << ans << endl;
}