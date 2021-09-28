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
  int A = 0;
  rep(i, 0, 15) {
    int x; cin >> x;
    if(x) A |= 1 << i;
  }

  auto donut = [&] (int _m) {
    bitset<16> m(_m);
    if(m[5] && m[6] && m[9] && m[10]) return false;
    if(!m[5]) {
      if(!m[1] || !m[4]) return false;
    }
    if(!m[6]) {
      if(!m[2] || !m[7]) return false;
    }
    if(!m[9]) {
      if(!m[8] || !m[13]) return false;
    }
    if(!m[10]) {
      if(!m[11] || !m[14]) return false;
    }
    return true;
  };

  auto cross = [&] (int _m) {
    bitset<16> m(_m);
    vector<int> candidate = {0, 1, 2, 4, 5, 6, 8, 9, 10};
    for(int i : candidate) {
      if(m[i]==m[i+5] && m[i+1]==m[i+4] && m[i]!=m[i+1]) return true;
    }
    return false;
  };

  auto connected = [&] (int _m) {
    bitset<16> m(_m);
    UnionFind uf(16);
    rep(i, 0, 15) rep(k, 0, 3) {
      if(int l = i-1; 0<=l && l%4 < i%4 && m[l]==m[i]) uf.merge(l, i);
      if(int r = i+1; r<16 && i%4 < r%4 && m[r]==m[i]) uf.merge(r, i);
      if(int u = i-4; 0<=u && m[u]==m[i]) uf.merge(u, i);
      if(int d = i+4; d<16 && m[d]==m[i]) uf.merge(d, i);
    }
    int root = -1;
    rep(i, 0, 15) if(A>>i & 1) {
      if(root == -1) root = i;
      else if(!uf.same(root, i)) return false;
    }

    rep(i, 0, 15) if(m[i] && !uf.same(root, i)) return false;

    return true;
  };

  int ans = 0;
  rep(mask, 0, (1<<16)-1) {
    if(bitset<16>(mask & A).count() != bitset<16>(A).count()) continue;
    if(donut(mask)) continue;
    if(cross(mask)) continue;
    if(!connected(mask)) continue;
    
    // rep(i, 0, 15) {
    //   cout << (mask>>i & 1)? 1 : 0;
    //   if(i%4==3) cout << endl;
    //   else cout << " ";
    // } 
    // cout << endl; 

    ans++;
  }

  cout << ans << endl;
}
