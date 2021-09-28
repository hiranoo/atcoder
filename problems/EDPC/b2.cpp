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

void chmin(int &a, int b) {
  a = min(a, b);
}
int main(){
  int n, k; cin >> n >> k;
  vector<int> h(n);
  rep(i, 0, n-1) cin >> h[i];
  
  const int INF = 1e9;

  vector<int> dp(n, INF);
  dp[0] = 0;
  rep(i, 0, n-1) {
    rep(j, 1, k) {
      if(i+j <= n-1) dp[i+j] = min(dp[i+j], dp[i]+abs(h[i+j]-h[i]));
    }
  }

  //rep(i, 0, n-1) cout << dp[i] << endl;
  cout << dp[n-1] << endl;
}