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
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n; cin >> n;
  vector<ll> a(n), sum(n+1);
  rep(i, 0, n-1) cin >> a[i];
  sum[0] = 0;
  rep(i, 1, n) sum[i] = sum[i-1] + a[i-1];
  
  // vector dp(n+2, vector<ll>(n+2, 0));
  // vector b(n+2, vector<ll>(n+2, -1));
  // b[1][0] = 0;
  // dp[0][0] = 1;
  // rep(i, 1, n) {
  //   rep(j, 1, n) {
  //     if(b[j][sum[i]%j] != -1) {
  //       dp[i][j] = dp[b[j][sum[i]%j]][j] + dp[b[j][sum[i]%j]][j-1];
  //       dp[i][j] %= MOD;
  //     }
  //     b[j][sum[i]%j] = i;
  //   }
  // }

  vector dp(n+2, vector<ll>(n+2, 0));
  vector ds(n+2, vector<ll>(n+2, 0));
  dp[0][0] = 1;
  ds[1][0] = 1;
  rep(i, 1, n) {
    for(int j = i; j >= 1; j--) {
      dp[i][j] = ds[j][sum[i]%j];
      ds[j+1][sum[i]%(j+1)] += dp[i][j];
      ds[j+1][sum[i]%(j+1)] %= MOD;
    }
  }

  // rep(j, 1, n) cout << dp[n][j] << " "; cout << endl;

  ll ans = 0;
  rep(j, 1, n) ans += dp[n][j], ans %= MOD;
  cout << (ans + MOD) % MOD << endl;
}