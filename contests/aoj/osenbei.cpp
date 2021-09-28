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

int solve(vector< vector<int> > &a, int r, int c){
  int ans = 0;
  rep(s, 0, (1 << r)-1){
    int sum = 0;
    rep(i, 0, c-1){
      int omote = 0;
      rep(j, 0, r-1){
        if(s & (1 << j)) omote += 1 - a[j][i];
        else omote += a[j][i];
      }
      sum += max(omote, r - omote);
    }
    ans = max(ans, sum);
  }

  return ans;
}

int main(){
  vector<int> ans(0);
  while(true){
    int r, c; cin >> r >> c;
    if(r == 0 && c == 0) break;
    vector< vector<int> > a(r, vector<int>(c));
    rep(i, 0, r-1) rep(j, 0, c-1) cin >> a[i][j];
    ans.push_back(solve(a, r, c));
  }

  rep(i, 0, ans.size()-1){
    cout << ans[i] << endl;
  }
}
