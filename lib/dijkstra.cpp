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
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;


// graphをmapでもたせてあるので、コストが変動する辺を含む経路でも使える
// graphの初期化方法：
//   map<int, ll> mp; // key=頂点, value=コスト
//   vector<map<int, ll>> G(n, map<int, ll>(mp)); 

vector<ll> dijkstra(int s, vector< map<int, ll> > &G) {
  priority_queue< P, vector<P>, greater<P> > que;
  que.push(P(0, s));
  int n = G.size();
  vector<ll> d(n, INF);
  d[s] = 0;
  
  while(que.size()) {
    P p = que.top(); que.pop();
    int v = p.second;

    if(d[v] < p.first) continue;
    
    for(auto itr = G[v].begin(); itr != G[v].end(); itr++) {
      int to = itr->first;
      ll cost = itr->second;
      if(d[to] > d[v] + cost){
        d[to] = d[v] + cost;
        que.push(P(d[to], to));
      }
    }
  }
  return d;
}

/*** O(V logV) ***/
struct edge {int to; ll cost;};
vector<ll> dijkstra(int s, vector< vector<edge> > &G) {
  int n = G.size();
  vector<ll> d(n, INF);
  d[s] = 0;
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

/*** O(V^2) ***/
struct edge {int to; ll cost;};
vector<ll> dijkstra(int s, vector< vector<edge> > &G) {
  int n = G.size();
  vector<ll> d(n, INF);
  d[s] = 0;
  vector<bool> used(n, false);

  while(true) {
    int v = -1;
    for(int u = 0; u < n; u++) {
      if(!used[u] && (v==-1 || d[u] < d[v])) v = u;
    }

    if(v == -1) break;

    used[v] = true;
    for(auto e : G[v]) {
      d[e.to] = min(d[e.to], d[v] + e.cost);
    }
  }
  return d;
}


int main() {
  int n, m; cin >> n >> m;
  vector< vector<edge> > G(n, vector<edge>(0));
  rep(i, 0, m-1) {
    int u, v; ll cost; cin >> u >> v >> cost; u--; v--;
    G[u].push_back((edge){v, cost});
  }

  for(auto dis : dijkstra(0, G)){
    cout << dis << endl;
  }
}

