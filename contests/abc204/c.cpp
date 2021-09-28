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
#define MAX_N 2005

int n, m;
vector<vector<int>> G(MAX_N, vector<int>(0));

int dfs(int s){
  ll ans = 0;
  stack<int> stk;
  stk.push(s);
  vector<bool> used(n, false);
  while(stk.size()){
    int v = stk.top(); stk.pop();

    if(used[v]) continue;
    used[v] = true;
    ans++;

    for( auto nv : G[v] ){
      stk.push(nv);
    }
  }

  return ans;
}

int main(){
  cin >> n >> m;
  rep(i, 0, m-1){
    int a, b; cin >> a >> b;
    G[a-1].push_back(b-1);
  }
  //cout << 111 << endl;
  if(m==0){
    cout << n << endl;
    return 0;
  }
  //cout << 1111 << endl;
  // dfs
  ll ans = 0;
  rep(i, 0, n-1){
    ans += dfs(i);
  }

  cout << ans << endl;

  return 0;
}