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
#define INF 1000000

typedef struct EDGE{
  int a, b; ll c, d;
} edge;

int n, m;
vector<edge> E(0);
vector<bool> used(n, false);

int calc_tp(ll c, ll d, int t){
  ll l=t, r=1000000;
  while(r-l>1){
    ll x = (l+r)/2;
    if(c + d/t > c + d/x + (x - t)) l = x;
    else r = x;
  }
  
  return l;
}

// 再帰関数じゃないとusedを戻せない？？
int dfs(){
  int ans = 1000000;
  stack<pii> stk;
  stk.push(pii(0, 0));
  vector<bool> used(n, false);
  while(stk.size()){
    pii v = stk.top(); stk.pop(); // first: node id, second: took time
    if(used[v.first]) continue;

    if(v.first == n-1){
      ans = max(ans, v.second);
      continue;
    }

    used[v.first] = true;

    rep(i, 0, m-1){
      edge e = E[i]; int nv = -1;
      if(e.a == v.first) nv = e.b;
      if(e.b == v.first) nv = e.a;
      if(nv == -1) continue;

      int t = calc_tp(e.c, e.d, v.second);
      stk.push(pii(nv, t));
    }    
  }

  if(ans == 1000000) ans = -1;
  return ans;
}

int ans = INF;

void dfs(int v, int t){ 
  if(v == n-1){
    ans = min(ans, t);
    return;
  }

  rep(i, 0, m-1){
    edge e = E[i]; int nv = -1;
    if(e.a == v) nv = e.b;
    if(e.b == v) nv = e.a;
    if(nv == -1) continue;
    if(used[nv]) continue;

    int nt = calc_tp(e.c, e.d, t);
    
    used[nv] = true;
    dfs(nv, nt);
    used[nv] = false;
  }
}

int main(){
  cin >> n >> m;
  rep(i, 0, m){
    int a, b; ll c, d;
    cin >> a >> b >> c >> d;
    E.push_back((edge){a-1, b-1, c, d});
  }

  dfs(0, 0);
  if(ans == INF) ans = -1;

  cout << ans << endl;

  return 0;
}