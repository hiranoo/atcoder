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
const ll INF = 1e18;

vector<ll> sum_a(500, 0);

ll f(int l , int r, vector<ll> &a, vector<vector<ll>> &dp, vector<vector<bool>> &flag) {
  if(flag[l][r]) return dp[l][r];

  ll fans = INF;
  ll sum = 0;
  if(r) sum += sum_a[r-1];
  if(l) sum -= sum_a[l-1];

  rep(k, l+1, r-1) fans = min(fans, f(l, k, a, dp, flag)+f(k, r, a, dp, flag) + sum);
  flag[l][r] = true;
  return dp[l][r] = fans;
}

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];
  vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
  vector<vector<bool>> flag(n+1, vector<bool>(n+1, false));
  rep(i, 0, n-1) {
    dp[i][i+1] = 0;
    flag[i][i+1] = true;
  }

  sum_a[0] = a[0];
  rep(i, 1, n-1) sum_a[i] = sum_a[i-1] + a[i];

  ll ans = f(0, n, a, dp, flag);
  cout << ans << endl;
}