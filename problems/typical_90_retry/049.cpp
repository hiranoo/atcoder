#include <bits/stdc++.h>
#include <atcoder/all>
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
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

struct UnionFind {
  vector<int> par, sz;
  int n;
  UnionFind(){}
  UnionFind(int _n) {
    n = _n;
    par.resize(n);
    sz.resize(n);
    rep(i, 0, n-1) par[i] = i, sz[i] = 1;
  }

  int find(int u) {
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
  }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    par[u] = v;
    sz[v] = sz[v]+sz[u];
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }

  int size(int u) {
    return sz[find(u)];
  }
};

struct Edge {
  int u, v; ll cost;
  bool operator<(const Edge &e) {
    return cost < e.cost;
  }
  bool operator==(const Edge &e) {
    return u==e.u && v==e.v && cost==e.cost;
  }
};

ll kruskal(vector<Edge> &E, int n) {
  ll ans = 0;
  int cnt = 0;
  UnionFind uf(n+1);
  for(Edge e : E) {
    if(cnt >= n) break;
    if(uf.same(e.u, e.v)) continue;
    uf.merge(e.u, e.v);
    ans += e.cost;
    cnt++;
  }

  if(cnt >= n) return ans;
  return -1;
}

int main() {
  int n, m; cin >> n >> m;
  vector<Edge> E(m);
  rep(i, 0, m-1) cin >> E[i].cost >> E[i].u >> E[i].v, E[i].u--;
  sort(all(E));

  cout << kruskal(E, n) << endl;
}