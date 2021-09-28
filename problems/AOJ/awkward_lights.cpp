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


bool solve(vector< vector<int> > &a, int m, int n, int d){
  for(ll s = 0; s < (1 << n); s++){
    rep(h, 0, n-1){
      if(!(s && 1<<h)) continue;
      
    }
  }
  return ans;
}

int main(){
  while(true){
    vector<bool> ans(0);
    int m, n, d; cin >> m >> n >> d;
    if(m == 0 && n == 0 && d == 0) break;
    vector< vector<int> > s(n, vector<int>(m));
    rep(h, 0, n-1) rep(w, 0, m-1) cin >> s[h][w];
    ans.push_back(solve(a, m, n, d));
  }

  rep(i, 0, ans.size()-1) cout << ans[i] << endl;
}