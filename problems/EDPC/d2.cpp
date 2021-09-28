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
  int n, w; cin >> n >> w;
  vector<pii> items(n);
  rep(i, 0, n-1) cin >> items[i].first >> items[i].second;

  vector<vector<ll>> dp(n+1, vector<ll>(w+1, 0));
  rep(i, 0, n-1) rep(j, 0, w) {
    dp[i+1][j] = dp[i][j];
    if(j >= items[i].first) dp[i+1][j] = max(dp[i+1][j], dp[i][j - items[i].first] + items[i].second);
  }

  cout << dp[n][w] << endl;
}