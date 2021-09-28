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

// ll f(int i, int j, vector<ll> &a, vector<vector<ll>> &dp, vector<vector<bool>> &flag) {
  
// }

int main(){
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];
  vector<vector<ll>> dp(n, vector<ll>(k+1, 0));
  vector<vector<bool>> flag(n, vector<bool>(k+1, false));
 
 rep(i, 0, n-1) {dp[i][0] = 1; flag[i][0] = true;}
 rep(j, 0, a[0]) dp[0][j] = 1;
 //rep(j, 0, a[i]) {dp[0][j] = 1; flag[0][j] = true;}

  rep(i, 1, n-1) rep(j, 0, k) {
    if(i > 0) dp[i][j] = dp[i-1][j];
    if(j > 0) dp[i][j] += dp[i][j-1];
    if(a[i] > 0 && j-1-a[i]>=0) dp[i][j] -= dp[i-1][j-1-a[i]];
    dp[i][j] %= MOD;
  }

  // rep(i, 1, n-1) rep(j, 0, k) {
  //   ll ret = dp[i-1][j];
  //   if(j > 0) ret += dp[i][j-1];
  //   if(a[i] > 0 && j-a[i]-1 >= 0) ret -= dp[i-1][j-a[i]-1];
  //   dp[i][j] = ret % MOD;
  // }
  
  cout << dp[n-1][k] << endl;
}