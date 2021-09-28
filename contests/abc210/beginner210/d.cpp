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

const ll INF = 1000000000000;

ll f() {
  vector<vector<ll>> dp(h, vector<ll>(w, INF));
  dp[0][0] = a[0][0];

  rep(i, 0, h-1) rep(j, 0, w-1) {
    if(i+1 < h) dp[i+1][j] = min(dp[i+1][j], dp[i][j]+c);
    if(j+1 < w) dp[i][j+1] = min(dp[i][j+1], dp[i][j]+c);
  }

  ll ans = INF;
  rep(i, 0, h-1) rep(j, 0, w-1) ans = min(ans, dp[i][j]);
  return ans;
}

int main(){
  ll h, w, c; cin >> h >> w >> c;
  vector<vector<ll>> a(h, vector<ll>(w));
  rep(y, 0, h-1) {
    rep(x, 0, w-1) {
      ll buf; cin >> buf;
      a[y][x] = buf;
    }
  }

  vector<vector<ll>> dp(h, vector<ll>(w, INF));
  dp[0][0] = a[0][0];

  rep(i, 0, h-1) rep(j, 0, w-1) {
    if(i+1 < h) dp[i+1][j] = min(dp[i+1][j], dp[i][j]+c);
    if(j+1 < w) dp[i][j+1] = min(dp[i][j+1], dp[i][j]+c);
  }

  ll ans = INF;
  rep(i, 0, h-1) rep(j, 0, w-1) ans = min(ans, dp[i][j]);
  return ans;

}