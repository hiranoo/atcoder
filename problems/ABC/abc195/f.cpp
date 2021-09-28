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

const int n = 20;
const int n2 = 1<<n;
const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
  
// int main() {
//   ll a, b; cin >> a >> b;
//   vector<ll> dp(n2, 0);
//   dp[0] = 1;
//   for(ll x = a; x <= b; x++) {
//     int s = 0;
//     rep(i, 0, n-1) if(x % primes[i] == 0) s |= 1<<i;
//     rep(i, 0, n2-1) {
//       if(i&s) continue;
//       dp[i|s] += dp[i];
//     }
//   }
//   ll ans = 0;
//   rep(i, 0, n2-1) {
//     ans += dp[i];
//     // if(dp[i]) cout << bitset<11>(i) << " " << dp[i] << endl;
//   }
//   cout << ans << endl;
// }

int main() {
  ll a, b; cin >> a >> b;

  vector<vector<ll>> dp(b-a+2, vector<ll>(n2, 0));
  dp[0][0] = 1;

  for(ll x = a; x <= b; x++) {
    int i = x - a + 1;
    rep(j, 0, n2-1) dp[i][j] += dp[i-1][j];
    int s = 0;
    rep(k, 0, n-1) if(x % primes[k] == 0) s |= 1<<k;
    rep(j, 0, n2-1) if((j&s) == 0) dp[i][j|s] += dp[i-1][j];
  }

  ll ans = 0;
  rep(i, 0, n2-1) ans += dp[(int)(b-a+1)][i];
  cout << ans << endl;
}
