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
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  int r = 0;
  ll ans = 0;
  rep(l, 0, n-1){
    while(true){
      if(r < n-1 && a[r] < a[r+1]) r++;
      else break;
    }
    //cout << "l:" << l << " r:" << r << endl;
    ans += r - l + 1;
    if(l == r) r++;
  }
  cout << ans << endl;
}