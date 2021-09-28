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

ll calc(int a, int b){
  if(a > b) return 0;
  return (b+1)*(b-a+1) - (a+b)*(b-a+1)/2;
}

ll search(vector<ll> &a, ll &x){
  //cout << "x:" << x << endl;
  int n = a.size();
  ll sum = 0;
  ll ans = 0;
  /*
  int l = 0;
  rep(r, 0, n-1){
    sum += a[r];
    while(sum > x){
      sum -= a[l++];
    }
    ans += r - l + 1;
  }
  */
  int r = 0;
  rep(l, 0, n-1){
    while(r < n && sum + a[r] <= x){
      sum += a[r++];
    }
    
    ans += r-l;
    sum -= a[l];
    
  }
  return ans;
}

int main(){
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  vector<ll> x(q);
  rep(i, 0, n-1) cin >> a[i];
  rep(i, 0, q-1) cin >> x[i];

  rep(i, 0, q-1){
    //cout << endl << "###################################" << endl;
    ll ans = search(a, x[i]);
    cout << ans << endl;
  }
}