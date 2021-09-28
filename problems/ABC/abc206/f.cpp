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

string solve(vector<pii> &s, int n){
  vector<vector<int>> children(n, vector<int>(0));
  rep(i, 0, n-1){
    rep(j, 0, n-1){
      if(i == j) continue;
      if(s[i].second <= s[j].first || s[j].second <= s[i].first) continue;
      children[i].push_back(j);
    }
  }
}

int main(){
  int T; cin >> T;
  vector<string> ans(T);
  rep(i, 0, T-1){
    int n; cin >> n;
    vector<pii> s(n);
    rep(j, 0, n-1){
      int l, r; cin >> l >> r;
      s[i] = pii(l,r);
    }
    ans.push_back(solve(s, n));
  }

  for(auto v : ans) cout << v << endl;
  return 0;
}