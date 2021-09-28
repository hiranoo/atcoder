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
template<typename T> bool chmax(T &m, const T q) {
    if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) {
    if (m > q) {m = q; return true;} else return false; }
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;

int main(){
  int n, w; cin >> n >> w;
  vector<pii> goods(n);
  rep(i, 0, n-1) cin >> goods[i].first >> goods[i].second;

  const ll INF = 1000000000;
  vector<vector<ll>> dp(n+1, vector<ll>(100005, INF));
  dp[0][0] = 0;

  rep(i, 0, n-1) rep(j, 0, 100001) {
    if(j < goods[i].second) dp[i+1][j] = dp[i][j];
    else dp[i+1][j] = min(dp[i][j], dp[i][j - goods[i].second] + goods[i].first);
  }

  int ans = 0;

  ll max_v = 0;
  for(auto g : goods) max_v += g.second;

  rep(j, 0, 10000) if(dp[n][j] <= w) ans = max(ans, j);
  cout << ans << endl;
}