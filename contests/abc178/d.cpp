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

int myceil(int v, int k) {
  if(v%k == 0) return v/k;
  return v/k+1;
}

int main() {
  int s; cin >> s;
  vector<ll> dp(s+1, 0);
  dp[0] = 1;
  ll x = 0;
  rep(i, 1, s) {
    if(i >= 3) {
      x += dp[i-3];
      x %= MOD;
    }
    dp[i] = x;
  }
  cout << dp[s] << endl;
}