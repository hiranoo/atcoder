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
/*
vector<vector<int>> dp(2, vector<int>(100005, 0));

int f(vector<int> &a, int turn, int stones) {
  //cout << turn << " " << stones << endl;
  if(dp[turn][stones] != 0) return dp[turn][stones];
  if(stones < a[0]) return dp[turn][stones] = 1-turn;
  for(auto v : a) if(v == stones) return dp[turn][stones] = turn;

  int ret = 1-turn;
  for(auto v : a) {
    if(v > stones) continue;
    if(f(a, 1-turn, stones-v) == turn){
      ret = turn;
      break;
    }
  }

  return ret;
}
*/
/*
vector<int> dp(100005, -1);

int f(vector<int> &a, int turn, int stones) {
  if(dp[stones] != -1) return (dp[stones]+turn)%2;
  if(stones < a[0]) return dp[stones] = 1-turn;
  for(auto v : a) if(v == stones) return dp[stones] = turn;

  int ret = 1 - turn;
  for(auto v : a) {
    if(v > stones) continue;
    if(f(a, 1-turn, stones-v) == turn) {
      ret = turn;
      break;
    }
  }
  return dp[stones] = ret;
}
*/

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  vector<int> dp(200005, 1); // 0: 勝ち, 1: 負け
  dp[0] = 1;
  rep(s, 0, k) {
    rep(i, 0, n-1) {
      if(dp[s] == 1) dp[s + a[i]] = 0;
    }
  }

  //rep(i, 0, k) cout << i << ": " << dp[i] << endl;

  if(dp[k] == 0) cout << "First" << endl;
  else cout << "Second" << endl;
}