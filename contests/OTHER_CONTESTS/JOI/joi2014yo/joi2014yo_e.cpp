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
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9+7;
const ll INF = 1e18;
struct edge{int to; ll cost;};

vector<ll> dijkstra(int s, vector< vector<edge> > &G) {
  int n = G.size();
  vector<ll> d(n, INF);
  d[s] = 0;
  typedef pair<ll, int> P;
  priority_queue< P, vector<P>, greater<P> > que;
  que.push(P(0, s));

  while(que.size()) {
    P p = que.top(); que.pop();
    int v = p.second;
    
    if(d[v] < p.first) continue;

    for(auto e : G[v]) {
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
  return d;
}

vector<bool> bfs(int s, int len, vector< vector<int> > &G) {
  int n = G.size();
  vector<bool> used(n, false);
  queue<pii> que;
  que.push(pii(0, s));
  while(que.size()) {
    pii p = que.front(); que.pop();
    int dep = p.first;
    int v = p.second;
    if(used[v] || dep > len) continue;
    used[v] = true;
    for(auto nv : G[v]) {
      if(used[nv]) continue;
      que.push(pii(dep+1, nv));
    }
  }
  return used;
}

int main() {
  int n, m; cin >> n >> m;
  vector<pii> taxi(n); // 運賃, 最大走行距離
  vector< vector<int> > G(n, vector<int>(0));
  // cout << "aaa" << endl;
  rep(i, 0, n-1) cin >> taxi[i].first >> taxi[i].second;
  // cout << "taxi done" << endl;
  rep(i, 0, m-1) {
    int a, b; cin >> a >> b; a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector< vector<edge> > E(n, vector<edge>(0));
  rep(i, 0, n-1) {
    // cout << "bfs " << i << endl;
    vector<bool> reachable = bfs(i, taxi[i].second, G);
    rep(j, 0, n-1) if(reachable[j]) E[i].push_back((edge){j, taxi[i].first});
  }
  
  vector<ll> ans = dijkstra(0, E);
  cout << ans[n-1] << endl;
}