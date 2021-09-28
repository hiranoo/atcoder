#include <iostream>
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
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;

ll search(vector<ll> &a, ll &k){
  ll l = -1, r = 1100000000000000000;
  while(r -l > 1){
    ll x = (l+r)/2;
    int y = upper_bound(all(a), x) - a.begin();
    if(x >= k + y) r = x;
    else l = x;
  }

  return r;
}

int main(){
  int n, q; cin >> n >> q;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];
  rep(i, 0, q-1){
    ll k; cin >> k;
    ll ans = search(a, k);
    cout << ans << endl;
  }
  return 0;
}