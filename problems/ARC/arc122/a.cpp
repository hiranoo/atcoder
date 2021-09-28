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
const ll INF = 1e18;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];

  if(n == 1) {
    cout << a[0] << endl;
    return 0;
  }
  if(n == 2) {
    cout << 2*a[0] << endl;
    return 0;
  }

  vector<vector<ll>> dp(n, vector<ll>(2));
  dp[0][0] = a[0]; dp[0][1] = 0;

  vector<ll> f(n+1);
  f[0] = 1, f[1] = 1;
  rep(i, 2, n) f[i] = (f[i-1] + f[i-2]) % MOD;

  dp[1][0] = (a[0] + a[1]) % MOD;
  dp[1][1] = (a[0] - a[1]) % MOD;
  
  rep(i, 2, n-1) {
    dp[i][0] = (dp[i-1][0] + dp[i-1][1] + f[i] * a[i]) % MOD;
    dp[i][1] = (dp[i-1][0] - f[i-1] * a[i]) % MOD;
  }

  // rep(i, 0, n-1) cout << i << " : " << f[i] << " " << dp[i][0] << " " << dp[i][1] << endl;

  ll ans = dp[n-1][0] + dp[n-1][1];
  ans %= MOD;
  cout << (ans + MOD) % MOD << endl;
}