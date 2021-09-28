#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

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

int main(){
  UnionFind tree(8);
  tree.unit(0, 1);
  tree.unit(0, 5);
  tree.unit(6, 4);
  tree.unit(4, 7);
  tree.display();

  cout << " D" << tree.find(6) << endl;
}