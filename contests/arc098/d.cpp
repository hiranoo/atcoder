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
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;

int main(){
  int n; cin >> n;
  vector<ull> a(n);
  rep(i, 0, n-1) cin >> a[i];

  int r = 0;
  ull sum = 0;
  ll ans = 0;
  rep(l, 0, n-1){
    while(r < n){
      bool ok = true;
      rep(i, 0, 19){
        if( ( sum & (1 << i) ) && ( a[r] & (1 << i) ) ){
          //cout << "sum:" << bitset<4>(sum) << " a[r]:" << bitset<4>(a[r]) << " i:" << i << endl;
          ok = false; break;
        }
      }
      if(ok) sum += a[r++];
      else break;
    }
    //cout << "l:" << l << " r:" << r << endl;
    ans += r - l;
    if(l == r) r++;
    sum -= a[l];
  }

  cout << ans << endl;
}