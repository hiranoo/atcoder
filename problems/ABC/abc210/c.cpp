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
#define rep(i, s, t) for(ll i = (s); i <= (t); i++)
#define repd(i, s, t) for(ll i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;

int main() {
  int n, k; cin >> n >> k;
  vector<int> c(n);
  rep(i, 0, n-1) cin >> c[i];

  map<int, int> mp;

  // init
  int res = 0;
  rep(i, 0, k-1) {
    if(mp[c[i]] == 0) {
      res++;
    }
    mp[c[i]]++;
  }

  int ans = res;
  rep(i, 0, n-k+1) {
    if(i+k >= n) break;
    if(mp[c[i+k]] == 0) {
      res++;
    }
    mp[c[i+k]]++;
    mp[c[i]]--;
    if(mp[c[i]] == 0) res--;
    ans = max(ans, res);
  }

  cout << ans << endl;
}

/*
int main(){
  ll n, k; cin >> n >> k;
  vector<ll> c(n);
  rep(i, 0, n-1) cin >> c[i];

  map<ll, ll> mp;
  ll res = -1;
  for(ll i = 0; i < k; i++) {
    mp[c[i]]++;
  }
  res = (ll)mp.size();

  for(ll i = k; i < n; i++) {
    mp[c[i]]++;
    mp[c[i-k]]--;
    if(mp[c[i-k]] == 0) mp.erase(c[i-k]);
    res = max(res, (ll)mp.size());
  }

  cout << res << endl;
}
*/

