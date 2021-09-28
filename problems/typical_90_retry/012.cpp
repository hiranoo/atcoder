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
const ll MOD = 1e9+7;
const ll INF = 1e16;
int h, w;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool chmax(ll &a, ll b) {if(a < b) {a = b; return true;} return false;}
bool chmin(ll &a, ll b) {if(a > b) {a = b; return true;} return false;}

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

bool inside(int x, int y) {
  if(x < 0 || x >= w || y < 0 || y >= h) return false;
  return true;
}

int main() {
  cin >> h >> w;
  int q; cin >> q;
  UnionFind tree(h*w);
  vector<vector<bool>> red(h, vector<bool>(w, false));
  
  rep(i, 0, q-1) {
    int typ; cin >> typ;
    if(typ == 1) {
      int r, c; cin >> r >> c; r--; c--;
      red[r][c] = true;
      rep(j, 0, 3) {
        int y = r + dy[j], x = c + dx[j];
        if(inside(x, y) && red[y][x]) tree.merge(r*w+c, y*w+x);
      }
    }else{
      int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
      y1--; x1--; y2--; x2--;
      if(red[y1][x1] && red[y2][x2] && tree.same(y1*w+x1, y2*w+x2)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}