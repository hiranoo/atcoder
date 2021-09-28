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
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e16;

struct Edge {int to; ll cost;};

vector<ll> dijkstra(int s, vector< vector<Edge> > &G) {
  int n = G.size();
  vector<ll> d(n, INF);
  d[s] = 0;
  priority_queue<P, vector<P>, greater<P>> q;
  q.push(P(0, s));
  while(q.size()) {
    P p = q.top(); q.pop();
    int u = p.second;
    if(d[u] < p.first) continue;
    for(auto e : G[u]) {
      if(d[e.to] > d[u] + e.cost) {
        d[e.to] = d[u] + e.cost;
        q.push(P(d[e.to], e.to));
      }
    }
  }
  return d;
}


int main() {
  int n, m; cin >> n >> m;
  vector<vector<Edge>> G(n);
  rep(i, 0, m-1) {
    int a, b, c; cin >> a >> b >> c; --a; --b;
    G[a].push_back((Edge){b, c});
    G[b].push_back((Edge){a, c});
  }

  vector<ll> d1 = dijkstra(0,G);
  vector<ll> d2 = dijkstra(n-1, G);

  rep(k, 0, n-1) cout << d1[k] + d2[k] << endl;
}