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
#define bit(n, k) (n & (1LL<<k))

ll f(ll s, vector<vector<ll>> &cost, vector<ll> &dp, vector<bool> &flag) {
  //cout << bitset<17>(s) << endl;
  if(flag[s]) return dp[s];

  ll res = 0;
  int n = cost.size();
  rep(i, 0, n-1) rep(j, i+1, n-1) if(bit(s, i) && bit(s, j)) res += cost[i][j];

  // rep(t, 1, s-1) {
  //   // t in s?
  //   bool sub = true;
  //   rep(i, 0, n-1) {
  //     if((t & (1<<i)) && !(s & (1<<i))) {
  //       sub = false;
  //       break;
  //     }
  //   }
  //   if(!sub) continue;

  //   res = max(res, f(t, cost, dp, flag) + f(s-t, cost, dp, flag));
  // }

  for(int t = s; t >= 0; t--) {
    t &= s;
    if(t==s || t==0) continue;
    res = max(res, f(t, cost, dp, flag) + f(s-t, cost, dp, flag)); 
  }

  flag[s] = true;
  return dp[s] = res;
}

int main(){
  int n; cin >> n;
  vector<vector<ll>> cost(n, vector<ll>(n, 0));

  rep(i, 0, n-1) rep(j, 0, n-1) cin >> cost[i][j];
  
  vector<ll> dp(1<<n, 0);
  vector<bool> flag(1<<n, false);
  rep(i, 0, n-1) flag[1<<i] = true;

  ll ans = f((1<<n)-1, cost, dp, flag);

  cout << ans << endl;
}