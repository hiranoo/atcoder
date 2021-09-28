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
  int n, K; cin >> n >> K;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  vector<bool> dp(K+5, false);
  sort(all(a));

  rep(j, 0, K) rep(i, 0, n-1) {
    if(j+a[i] > K) continue;
    if(!dp[j]) dp[j + a[i]] = true;
  }

  //for(auto v : dp) cout << v << " "; cout << endl;

  if(dp[K]) cout << "First" << endl;
  else cout << "Second" << endl;
}