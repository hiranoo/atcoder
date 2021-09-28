#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
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

const int INF = 100100100;

int gcd(int a, int b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  int n, m; cin >> n >> m;
  vector<pii> ac(m);
  rep(i, 0, m-1) {
    int a, c; cin >> a >> c;
    ac[i] = pii(c, a);
  }

  sort(all(ac));
  vector<int> x(m+1); x[0] = n;
  rep(i, 1, m) {
    x[i] = gcd(x[i-1], ac[i-1].second);
  }

  ll ans = 0;
  rep(i, 0, m-1) {
    ans += ac[i].first * (x[i] - x[i+1]);
  }


  if(x[m] > 1) cout << -1 << endl;
  else cout << ans << endl;
}