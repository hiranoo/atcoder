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
// const ll MOD = 1e9+7;
const ll MOD = 998244353;
const ll INF = 1e16;

void chmax(ll &a, ll b) {a = max(a, b);}
void chmin(ll &a, ll b) {a = min(a, b);}

int main() {
  int n; cin >> n;
  vector<pii> ab(n);
  rep(i, 0, n-1) cin >> ab[i].first;
  rep(i, 0, n-1) cin >> ab[i].second;

  sort(all(ab));

  vector<vector<ll>> dp(5001, vector<ll>(5001, 0));
  dp[0][0] = 1;
  
  rep(i, 1, n) rep(j, 0, 5000) {
    dp[i][j] += dp[i-1][j];
    if(j >= ab[i-1].second) dp[i][j] += dp[i-1][j-ab[i-1].second];
    dp[i][j] %= MOD;
  }

  ll ans = 0;
  rep(i, 1, n) rep(j, 0, ab[i-1].first-ab[i-1].second) {
    ans += dp[i-1][j];
    ans %= MOD;
  }
  
  cout << (ans + MOD) % MOD << endl;
}