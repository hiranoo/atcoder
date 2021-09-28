#define _GLIBCXX_DEBUG
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
//#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define ALL(a) a.begin(), a.end()
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;

const ll INF = pow(10, 18);

int main(){
  int n, k; cin >> n >> k;
  vector<ll> a(n), b(n);
  rep(i, 0, n-1) cin >> a[i];
  rep(i, 0, n-1) cin >> b[i];
  //sort(ALL(a));
  sort(ALL(b));

  ll l = -1;
  ll r = ll(9*1e18);
  ll count = 0;
  while(r-l > 1){
    count = 0;
    ll x = (l+r)/2;
    //cout << "x:" << x << endl;
    rep(i, 0, n-1){
      count += upper_bound(ALL(b), (ll)(x/a[i])) - b.begin();
      //cout << x/a[i] << " 以下の値の個数: " << tmp << endl;
    }
    //cout << x << " 以下の値の個数: " << count << endl;
    if(count >= k) r = x;
    else l = x;
  }
  cout << l+1 << endl;
}