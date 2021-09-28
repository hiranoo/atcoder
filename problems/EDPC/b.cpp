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
  int n, k; cin >> n >> k;
  vector<int> h(n);
  rep(i, 0, n-1) cin >> h[i];

  const int INF = 1000000000;

  vector<int> dp(n, INF);
  dp[0] = 0;
  
  for(int i = 1; i < n; i++) {
   for(int j = i; j >= max(0, i-k); j--) {
     dp[i] = min(dp[i], dp[j]+abs(h[j] - h[i]));
   }
  }

  cout << dp[n-1] << endl;
}