#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
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

int main(){
  string k_str; int d;
  cin >> k_str >> d;

  vector<int> digit;
  digit.push_back(0);
  for(auto v : k_str) digit.push_back(v-'0');

  int len = k_str.size();

  //ll dp[len+1][2][2][d];
  //rep(i, 0, len) rep(j, 0, 1) rep(k, 0, 1) rep(l, 0, d-1) dp[i][j][k][l] = 0;
  vector<vector<vector<vector<ll>>>> dp(len+1, vector<vector<vector<ll>>>(2, vector<vector<ll>>(2, vector<ll>(d, 0))));

  dp[0][0][1][0] = 1;

  rep(i, 1, len) {
    rep(j, 0, d-1) {
      int nj = (j + digit[i]) % d;
      dp[i][0][1][nj] += dp[i-1][0][1][j];
      dp[i][0][1][nj] %= MOD;

      rep(k, 0, 9) {
        int nj = (j + k) % d;
        dp[i][1][1][nj] += dp[i-1][1][1][j];
        dp[i][1][1][nj] %= MOD;
      }

      rep(k, 0, digit[i]-1) {
        int nj = (j + k) % d;
        dp[i][1][1][nj] += dp[i-1][0][1][j];
        dp[i][1][1][nj] %= MOD;
      }
      rep(k, 1, 9) {
        int nj = (j + k) % d;
        dp[i][1][1][nj] += dp[i-1][1][0][j];
        dp[i][1][1][nj] %= MOD;
      }
    }
  }

  ll ans = dp[len][0][1][0] + dp[len][1][1][0] - 1 + MOD;
  cout << ans % MOD << endl;
}