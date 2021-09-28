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

void chmax(ll &a, ll b) {a = max(a, b);}

ll f(int l, int r, vector<ll> &a, vector<vector<ll>> &dp, vector<vector<bool>> &flag) {
  // cout << l << " " << r << endl;
  // if(l*r<0) return 0;
  if(flag[l][r]) return dp[l][r];

  ll fans = max(a[l] - f(l+1, r, a, dp, flag), a[r] - f(l, r-1, a, dp, flag));
  // cout << l << " " << r << " : " << fans << endl;
  
  flag[l][r] = true;
  return dp[l][r] = fans;
}

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];
  
  vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
  vector<vector<bool>> flag(n+1, vector<bool>(n+1, false));
  rep(i, 0, n-1) {dp[i][i] = a[i]; flag[i][i] = true; }
  rep(i, 0, n-1) rep(j, 0, i-1) {dp[i][j] = 0; flag[i][j] = true; }

  ll ans = f(0, n-1, a, dp, flag);

  cout << ans << endl;
}