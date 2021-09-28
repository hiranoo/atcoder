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
const ll INF = 1e17;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

ll op(ll a, ll b) {
  return a+b;
}

ll e() {return 0;}

struct UnionFind {
  vector<int> par, sz;
  int n = 0;
  UnionFind() {}
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
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(sz[x] > sz[y]) sz[x]=sz[y]=sz[x]+sz[y], par[y] = x;
    else sz[x]=sz[y]=sz[x]+sz[y], par[x] = y;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  int get_size(int x) {
    return sz[find(x)];
  }
};

int main1() {
  int n; cin >> n;
  int q; cin >> q;

  atcoder::segtree<ll, op, e> seg_even(n), seg_odd(n), seg_flag(n);
  rep(i, 0, n-1) seg_flag.set(i, 1);

  rep(qi, 0, q-1) {
    int typ; cin >> typ;
    ll x, y, v; cin >> x >> y >> v; x--; y--;
    if(typ==0) {
      if(x%2==0) seg_even.set(x/2, v);
      else seg_odd.set(x/2, v);
      seg_flag.set(x, 0);
    }else{
      bool swapped = false;
      if(x > y) swap(x, y), swapped=true;
      if(seg_flag.prod(x, y) > 0) {
        cout << "Ambiguous" << endl;
      }else{
        if(x%2==0 && y%2==0) {
          ll b = seg_even.prod(x/2, y/2) - seg_odd.prod(x/2, y/2);
          if(!swapped) cout << v - b << endl;
          else cout << v + b << endl;
        }else if(x%2==0 && y%2==1) {
          ll b = seg_even.prod(x/2, y/2+1) - seg_odd.prod(x/2, y/2);
          cout << b - v << endl;
        }else if(x%2==1 && y%2==0) {
          ll b = seg_odd.prod(x/2, y/2) - seg_even.prod(x/2+1, y/2);
          cout << b - v << endl;
        }else if(x%2==1 && y%2==1){
          ll b = seg_odd.prod(x/2, y/2) - seg_even.prod(x/2+1, y/2+1);
          if(!swapped) cout << v - b << endl;
          else cout << v + b << endl;
        }
      }
    }
  }

  return 0;
}

int main2() {
  int n, q; cin >> n >> q;
  vector<int> T(q), X(q), Y(q), V(q);
  for(int i = 0; i < q; i++) {
    cin >> T[i] >> X[i] >> Y[i] >> V[i];
    X[i]--, Y[i]--;
  }
  vector<int> sum(n-1, 0);
  for(int i = 0; i < q; i++) {
    if(T[i] == 0) sum[X[i]] = V[i];
  }

  vector<ll, ll> potential(n, 0);
  for(int i = 0; i < n-1; i++) {
    potential[i+1] = sum[i] - potential[i];
  }

  UnionFind uf(n);
  for(int i = 0; i < q; i++) {
    if(T[i] == 0) {
      uf.merge(X[i], Y[i]);
    }else{
      if(!uf.same(X[i], Y[i])) cout << "Ambiguous" << endl;
      else if((X[i]+Y[i])%2 == 0) {
        cout << potential[Y[i]] + V[i] - potential[X[i]] << endl;
      }else{
        cout << potential[Y[i]] - V[i] + potential[X[i]] << endl;
      }
    }
  }

  return 0;
}

int main() {
  // main1();
  main2();
}