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
typedef pair<ll, int> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;

#define bit(n, k) (n & (1<<k))

int myxor(int a, int b) {
  int ans = 0;
  rep(i, 0, 29) {
    if( (a & 1<<i) != (b & 1<<i) ) ans |= (1 << i);
  }
  return ans;
}

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  rep(i, 0, n-1) cin >> a[i];
  rep(i, 0, n-1) cin >> b[i];

  //sort(all(a));
  sort(all(b));

  set<int> xors;
  rep(i, 0, n-1) {
    xors.insert(a[0]^b[i]);
  }

  vector<int> ans;
  for(auto x : xors) {
    vector<int> c;
    for(auto aa : a) {
      c.push_back(aa^x);
    }
    sort(all(c));
    if(b == c) ans.push_back(x);
  }

  // sort(all(ans));
  cout << ans.size() << endl;
  for(auto v : ans) cout << v << endl;
}