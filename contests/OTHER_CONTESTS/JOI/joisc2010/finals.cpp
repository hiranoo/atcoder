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

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<edge> E;
  rep(i, 0, m-1) {
    int u, v, cost; cin >> u >> v >> cost;
    u--; v--;
    E.push_back(edge(u, v, cost));
  }

  sort(all(E));
  UnionFind tree(n);
  
  ll ans = 0;
  int cnt = 0;
  for(auto e : E) {
    if(n-cnt == k) break;
    if(!tree.same(e.u, e.v)) {
      tree.unit(e.u, e.v);
      ans += e.cost;
      cnt++;
    }
  }

  cout << ans << endl;
}