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

struct Edge {
  ll u, v, cost;
  bool operator<(const Edge &e) {
    return cost < e.cost;
  }
};


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

int main() {
  int n, m; cin >> n >> m;
  vector<Edge> E(m);
  rep(i, 0, m-1) cin >> E[i].u >> E[i].v >> E[i].cost, E[i].u--, E[i].v--;
  sort(all(E));

  UnionFind uf(n);
  int sz = 0;
  vector<int> removed;
  rep(i, 0, m-1) {
    if(E[i].cost < 0) {
      if(!uf.same(E[i].u, E[i].v)) sz++;
      uf.merge(E[i].u, E[i].v);
    }else{
      if(uf.same(E[i].u, E[i].v)) removed.push_back(i);
      else uf.merge(E[i].u, E[i].v), sz++;
    }
    if(sz >= n) break;
  }

  ll ans = 0;
  for(auto i : removed) ans += E[i].cost;
  cout << ans << endl;
}