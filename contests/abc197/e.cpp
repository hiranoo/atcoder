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

void chmax(ll &a, ll b) {a = max(a, b);}
void chmin(ll &a, ll b) {a = min(a, b);}

int main() {
  int n; cin >> n;
  vector<pll> range(n, pll(INF, -INF));
  rep(i, 0, n-1) {
    ll x; int c; cin >> x >> c; c--;
    chmin(range[c].first, x);
    chmax(range[c].second, x);
  }

  vector<pll> compressed;
  for(auto p : range) if(p.first  != INF && p.second != -INF) compressed.push_back(p);

  int m = compressed.size();
  vector<vector<ll>> dp(m, vector<ll>(2, INF));
  dp[m-1][0] = abs(compressed[m-1].first) + compressed[m-1].second - compressed[m-1].first;
  dp[m-1][1] = abs(compressed[m-1].second) + compressed[m-1].second - compressed[m-1].first;

  for(int i = m-2; i >= 0; i--) {
    chmin(dp[i][0], dp[i+1][0] + abs(compressed[i].first - compressed[i+1].second) + compressed[i].second - compressed[i].first);
    chmin(dp[i][0], dp[i+1][1] + abs(compressed[i].first - compressed[i+1].first) + compressed[i].second - compressed[i].first);
    chmin(dp[i][1], dp[i+1][0] + abs(compressed[i].second - compressed[i+1].second) + compressed[i].second - compressed[i].first);
    chmin(dp[i][1], dp[i+1][1] + abs(compressed[i].second - compressed[i+1].first) + compressed[i].second - compressed[i].first);
  }

  ll ans = INF;
  chmin(ans, dp[0][0] + abs(compressed[0].second));
  chmin(ans, dp[0][1] + abs(compressed[0].first));
  cout << ans << endl;
}