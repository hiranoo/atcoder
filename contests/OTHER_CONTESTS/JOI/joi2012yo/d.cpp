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
// const ll MOD = 1e9+7;
const ll INF = 1e18;


int main() {
  int n, K; cin >> n >> K;
  vector<int> d(n, -1);
  rep(i, 1, K) {
    int a, b; cin >> a >> b;
    d[a-1] = b-1;
  }

  vector< vector<ll> > dp(n+2, vector<ll>(9, 0));
  if(d[0] == -1 && d[1] == -1) rep(j, 0, 8) dp[1][j] = 1;
  else if(d[0] != -1 && d[1] == -1) rep(j, 0, 8) {
    if(j/3 == d[0]) dp[1][j] = 1;
    else dp[1][0] = 0;
  }else if(d[0] == -1 && d[1] != -1) rep(j, 0, 8) {
    if(j%3 == d[1]) dp[1][j] = 1;
    else dp[1][j] = 0;
  }else{
    rep(j, 0, 8) {
      dp[0][j] = 0;
      dp[1][j] = 0;
    }
    dp[1][ d[0]*3 + d[1] ] = 1;
  }

  const ll MOD = 10000;
  rep(i, 0, n-1) {
    dp[i+1][0] = (dp[i+1][0] + dp[i][3] + dp[i][6]) % MOD;
    dp[i+1][1] = (dp[i+1][1] + dp[i][0] + dp[i][3] + dp[i][6]) % MOD;
    dp[i+1][2] = (dp[i+1][2] + dp[i][0] + dp[i][3] + dp[i][6]) % MOD;
    dp[i+1][3] = (dp[i+1][3] + dp[i][1] + dp[i][4] + dp[i][7]) % MOD;
    dp[i+1][4] = (dp[i+1][4] + dp[i][1] + dp[i][7]) % MOD;
    dp[i+1][5] = (dp[i+1][5] + dp[i][1] + dp[i][4] + dp[i][7]) % MOD;
    dp[i+1][6] = (dp[i+1][6] + dp[i][2] + dp[i][5] + dp[i][8]) % MOD;
    dp[i+1][7] = (dp[i+1][7] + dp[i][2] + dp[i][5] + dp[i][8]) % MOD;
    dp[i+1][8] = (dp[i+1][8] + dp[i][2] + dp[i][5]) % MOD;

    if(d[i+1] != -1) rep(j, 0, 8) {
      if(d[i+1] != j%3) dp[i+1][j] = 0;
    }
  }

  ll ans = 0;
  rep(j, 0, 8) ans = (ans + dp[n-1][j]) % MOD;

  cout << (ans + MOD) % MOD << endl;
}