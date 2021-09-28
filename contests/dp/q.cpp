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

ll op(ll a, ll b) {
  if(a > b) return a;
  return b;
}

ll e() {
  return 0;
}

int main(){
  int n; cin >> n;
  vector<ll> h(n), a(n);
  rep(i, 0, n-1) cin >> h[i];
  rep(i, 0, n-1) cin >> a[i];

  vector<ll> dp(n, 0);
  dp[0] = a[0];
  atcoder::segtree<ll, op, e> sum(n+1);

  rep(i, 0, n-1) {
    dp[i] = sum.prod(0, h[i]) + a[i];
    sum.set(h[i], dp[i]);
  }

  ll ans = 0;
  for(auto v : dp) ans = max(ans, v);
  cout << ans << endl;
}
