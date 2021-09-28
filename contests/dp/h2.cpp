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
  int h, w; cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h-1) cin >> a[i];
  vector<vector<ll>> dp(h, vector<ll>(w, 0));
  dp[0][0] = 1;
  rep(i, 0, h-1) rep(j, 0, w-1) {
    if(a[i][j] == '#') continue;

    if(i > 0) dp[i][j] += dp[i-1][j];
    if(j > 0) dp[i][j] += dp[i][j-1];
    dp[i][j] %= MOD;
  }

  //rep(i, 0, h-1) rep(j, 0, w-1) cout << i << "," << j << " : " << dp[i][j] << endl;

  cout << dp[h-1][w-1] << endl;
}