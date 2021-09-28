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
  vector<int> h(n);
  rep(i, 0, n-1) cin >> h[i];

  vector<int> dp(n);
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  rep(i, 2, n-1) {
    dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
  }

  cout << dp[n-1] << endl;
}