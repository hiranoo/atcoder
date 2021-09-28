#include <bits/stdc++.h>
// #include <atcoder/segtree>
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

struct edge {
  int u, v, cost;
  edge(){}
  edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
  bool operator< (const edge &e) {
    return cost < e.cost;
  }
};

struct UnionFind {
  vector<int> par;
  int N;

  UnionFind(int n) : par(n) {
    N = n;
    for(int i = 0; i < n; i++){
      par[i] = i;
    }
  }
  
  int find(int x){
      if(par[x] == x) return x;
      return par[x] = find(par[x]);
  }

  void unit(int x, int y){
      x = find(x);
      y = find(y);
      if(x==y) return;
      par[x] = y;
  }

  bool same(int x, int y){
      return find(x) == find(y);
  }



  void display(){
    int used[N] = {0};
    for(int i = 0; i < N; i++){
      if(used[i]==1) continue;
      int p = i;
      if(p == par[p]){
        cout << p << endl;
        continue;
      }
      while(true){
        if(p == par[p]) break;
        cout << p << " -> ";
        used[p] = 1;
        p = par[p];
      }
    }
    cout << endl;
  }
};

bool compy(const pii &a, const pii &b) {
  if(a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

int main() {
  int n; cin >> n;
  vector<pii> v(n);
  map<pii, int> idx;
  rep(i, 0, n-1) {
    int a, b; cin >> a >> b;
    v[i] = pii(a, b);
    idx[pii(a, b)] = i;
  }

  vector<edge> E;

  sort(all(v));
  rep(i, 0, n-2) E.push_back(edge(idx[v[i]], idx[v[i+1]], abs(v[i+1].first - v[i].first)));

  sort(all(v), compy);
  rep(i, 0, n-2) E.push_back(edge(idx[v[i]], idx[v[i+1]], abs(v[i+1].second - v[i].second)));

  sort(all(E));
  UnionFind tree(n);
  
  ll ans = 0;
  for(auto e : E) {
    if(!tree.same(e.u, e.v)) {
      tree.unit(e.u, e.v);
      ans += e.cost;
    }
  }

  cout << ans << endl;
}