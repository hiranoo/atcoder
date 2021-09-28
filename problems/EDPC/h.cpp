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
const int MAX_N = 100005;


int main() {
  int h, w; cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h-1) cin >> a[i];

  vector<vector<ll>> dp(h, vector<ll>(w, 0));
  dp[0][0] = 1;

  rep(y, 0, h-1) rep(x, 0, w-1) {
    if(a[y][x] == '#') {
      dp[y][x] = 0;
      continue;
    }
    if(y+1 < h && a[y+1][x] == '.') {
      dp[y+1][x] += dp[y][x]; dp[y+1][x] %= MOD;
    }
    if(x+1 < w && a[y][x+1] == '.') {
      dp[y][x+1] += dp[y][x]; dp[y][x+1] %= MOD;
    }
  }

  cout << (dp[h-1][w-1] + MOD) % MOD << endl;
}