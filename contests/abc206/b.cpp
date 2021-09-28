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
  ll n; cin >> n;
  ll l = -1; ll r = 3*n;
  while(r-l > 1){
    ll k = (l+r)/2;
    if(k*(k+1)/2 >= n) r = k;
    else l = k;
  }
  if(l*(l+1)/2 >= n) cout << l << endl;
  else cout << r << endl;
  return 0;
}