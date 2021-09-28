
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

  // 数列sに0が含まれるならOK
  rep(i, 0, n-1){
    if(s[i] == 0){
      cout << n << endl;
      return 0;
    }
  }

  int r=0; ll product = 1;
  int ans = 0;
  rep(l, 0, n-1){
    //cout << "l:" << l << " r:" << r << " pro:" << product << endl;
    while(r < n && product * s[r] <= k) product *= s[r++];
    ans = max(ans, r-l);
    if(l == r) r++;
    else product /= s[l];
  }

  cout << ans << endl;
  return 0;
}