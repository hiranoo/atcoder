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

int main() {
  int n; cin >> n;
  vector<int> x(n), y(n);
  rep(i, 0, n-1) cin >> x[i] >> y[i];

  double l = 0, r = 101;
  while(r-l >= 0.000001) {
    double t = (l+r)/2.0;

    UnionFind uf(n+2); // super vertex: n, n+1
    rep(i, 0, n-1) {
      if(100-y[i] <= 2*t) uf.merge(i, n);
      if(y[i]+100 <= 2*t) uf.merge(i, n+1);
      rep(j, 0, n-1) if(i != j && (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= 4*t*t) uf.merge(i, j);
    }
    if(uf.same(n, n+1)) r = t;
    else l = t;
  }
  cout << fixed << setprecision(8) << l << endl;  
}