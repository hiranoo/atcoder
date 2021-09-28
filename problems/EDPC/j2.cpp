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

int n;

double f(int i, int j , int k, vector<vector<vector<double>>> &dp, vector<vector<vector<bool>>> &flag) {
  if(flag[i][j][k]) return dp[i][j][k];

  double p = n;
  if(i > 0) p += i * f(i-1, j+1, k, dp, flag);
  if(j > 0) p += j * f(i, j-1, k+1, dp, flag);
  if(k > 0) p += k * f(i, j, k-1, dp, flag);
  if(i+j+k > 0)p /= (double)(i+j+k);
  else p = 0;
  //cout << i << " " << j << " " << k << " : " << p << endl;
  flag[i][j][k] = true;
  return dp[i][j][k] = p;
}

int main(){
  cin >> n;
  int cnt[3] = {0};
  rep(i, 0, n-1) {
    int c; cin >> c; cnt[c-1]++;
  }

  vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(n+1, vector<double>(n+1)));
  vector<vector<vector<bool>>> flag(n+1, vector<vector<bool>>(n+1, vector<bool>(n+1, false)));

  double ans = f(cnt[2], cnt[1], cnt[0], dp, flag);
  cout << fixed << setprecision(10) << ans << endl;
}