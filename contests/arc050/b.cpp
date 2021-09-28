
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
#define all(v) v.begin(), v.end()
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;

bool judge(ll &R, ll &B, ll &x, ll &y, ll &z){
  if(R < z || B < z) return false;
  ll a = (R-z)/(x-1);
  ll b = (B-z)/(y-1);
  if(a + b >= z) return true;
  return false;
}

int main(){
  ll R, B; cin >> R >> B;
  ll x, y; cin >> x >> y;

  ll l = -1; ll r = min(R/x, B) + min(R, B/y) + 2;
  while(r - l > 1){
    ll z = (l + r)/2;

    bool c = judge(R, B, x, y, z);
    if(c) l = z;
    else r = z;
  }

  cout << l << endl;
}