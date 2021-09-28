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
  int n; cin >> n;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];

  vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
  //rep(i, 0, n-1) dp[i][i+1] = a[i];
  vector<ll> sum_a(n, 0);
  sum_a[0] = a[0];
  rep(i, 1, n-1) sum_a[i] = sum_a[i-1] + a[i];

  const ll INF = 1e18;

  rep(size, 2, n) {
    rep(i, 0, n-size) {
      ll res = INF;
      rep(k, i+1, i+size-1) {
        ll ret = dp[i][k]+dp[k][i+size]+sum_a[i+size-1];
        if(i>0) ret -= sum_a[i-1];
        res = min(res, ret);
      }
      dp[i][i+size] = res;
    }
  }
  cout << dp[0][n] << endl;
}