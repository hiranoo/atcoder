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
typedef pair<ll, int> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
struct edge{int to; ll cost;};

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

int main() {
  int n, m, s; cin >> n >> m >> s;
  vector<vector<edge>> G(n, vector<edge>(0));
  rep(i, 0, m-1) {
    int u, v; ll cost; cin >> u >> v >> cost;
    G[u].push_back((edge){v, cost});
  }

  for(auto dis : dijkstra(s, G)){
    if(dis == INF) cout << "INF" << endl;
    else cout << dis << endl;
  }

}