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
const ll INF = 1e16;

bool chmax(ll &a, ll b) {if(a < b) {a = b; return true;} return false;}
bool chmin(ll &a, ll b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n; cin >> n;
  string s; cin >> s;
  string t = "atcoder";

  vector<vector<ll>> dp(n+1, vector<ll>(8, 0));
  rep(i, 0, n) dp[i][0] = 1;
  rep(i, 1, n) rep(j, 1, 7) {
    dp[i][j] += dp[i-1][j];
    if(s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
    dp[i][j] %= MOD;
  }

  cout << (dp[n][7] + MOD) % MOD << endl;

  // cout << "i "; rep(i, 0, n) cout << " " << (i==0? '-' : s[i-1]); cout << endl;
  // rep(j, 0, 7) {
  //   cout << (j==0? '-' :t[j-1]) << " "; rep(i, 0, n) cout << " " << dp[i][j]; cout << endl;
  // }

}