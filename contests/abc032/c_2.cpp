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


int main(){
  int n; ll k;
  cin >> n >> k;
  vector<ll> s(n);
  rep(i, 0, n-1) cin >> s[i];

  int r = 0;
  ll mul = 1;
  int ans = 0;
  rep(l, 0, n-1){
    if(s[l]==0){
      ans = n;
      break;
    }
    while(r < n && mul * s[r] <= k){
      mul *= s[r++];
    }
    ans = max(ans, r-l);
    if(l == r) r++;
    else mul /= s[l];
  }
  cout << ans << endl;
}