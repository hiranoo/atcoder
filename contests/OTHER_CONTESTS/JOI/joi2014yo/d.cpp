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
const ll MOD = 10007;
const ll INF = 1e18;

int main() {
  int n; cin >> n;
  string str; cin >> str;
  vector<int> cheaf(n);
  rep(i, 0, n-1) {
    switch(str[i]) {
      case 'J':
        cheaf[i] = 0;
        break;
      case 'O':
        cheaf[i] = 1;
        break;
      case 'I':
        cheaf[i] = 2;
        break;
    }
  }

  vector<vector<int>> v(8, vector<int>(8, 0));
  v[1][1] = v[1][3] = v[1][5] = v[1][7] = 1;
  v[2][2] = v[2][3] = v[2][6] = v[2][7] = 1;
  v[3][1] = v[3][2] = v[3][3] = v[3][5] = v[3][6] = v[3][7] = 1;
  v[4][4] = v[4][5] = v[4][6] = v[4][7] = 1;
  v[5][1] = v[2][3] = v[2][4] = v[2][5] = v[2][6] = v[2][7] = 1;
  v[6][2] = v[6][3] = v[6][4] = v[6][5] = v[6][6] = v[6][7] = 1;
  v[7][1] = v[7][2] = v[7][3] = v[7][4] = v[7][5] = v[7][6] = v[7][7] = 1;

  vector< vector<ll> > dp(n, vector<ll>(8, 0));
  switch(cheaf[0]) {
    case 0:
      dp[0][1] = dp[0][3] = dp[0][5] = dp[0][7] = 1;
      break;
    case 1:
      dp[0][2] = dp[0][3] = dp[0][6] = dp[0][7] = 1;
      break;
    case 2:
      dp[0][4] = dp[0][5] = dp[0][6] = dp[0][7] = 1;
      break;
  }
  rep(i, 1, n-1) {
    rep(s, 1, 7) {
      if( !(s & 1<<cheaf[i]) ) continue;
      rep(j, 0, 7) if(v[s][j]) {
        dp[i][s] += dp[i-1][j];
        dp[i][s] %= MOD;
      }
    }
  }

  ll ans = 0;
  rep(i, 0, 7) ans += dp[n-1][i];
  ans %= MOD;
  cout << (ans + MOD) % MOD << endl;
}