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

int main() {
  string s; cin >> s;
  int n = s.size();
  string t = " chokudai";
  vector< vector<ll> > dp(9, vector<ll>(n+1, 0));

  rep(i, 0, n) dp[0][i] = 1;
  rep(j, 1, 8) {
    // cout << t[j] << endl;
    rep(i, 1, n) {
      if(s[i-1] != t[j]) dp[j][i] = dp[j][i-1];
      if(s[i-1] == t[j]) dp[j][i] = dp[j-1][i-1] + dp[j][i-1];
      dp[j][i] %= MOD;
    }
  }
  cout << (dp[8][n] + MOD) % MOD << endl;

  // cout << "  "; rep(i, 0, n-1) cout << s[i] << " "; cout << endl;
  // rep(j, 0, 3) {rep(i, 0, n) cout << dp[j][i] << " "; cout << endl;}
}