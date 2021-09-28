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
  vector<int> a(n);
  rep(i, 0, n-1) {
    cin >> a[i];
  }

  set<int> used;
  
  int r = 0;
  int ans = 0;
  rep(l, 0, n-1){
    while(r < n && used.count(a[r]) == 0) used.insert(a[r++]);
    ans = max(ans, r-l);
    used.erase(a[l]);
  }

  cout << ans << endl;

  /*
  map<int, int> imp;
  rep(i, 0, n-1) {
    imp[a[i]] = -1;
  }
  rep(i, 0, n-1) {
    if(imp[a[i]] == -1) imp[a[i]] = i;
  } 

  int r = 0;
  int ans = 0;
  
  rep(l, 0, n-1){
    while(r < n){
      if(imp[a[r]] == r || imp[a[r]] == -1){
        imp[a[r]] = r;
        r++;
      }
      else break;
    }
    //cout << "l:" << l << " r:" << r << endl;
    ans = max(ans, r - l);
    imp[a[l]] = -1;
  }
  
  cout << ans << endl;
  */
}