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
//#include <atcoder/segtree>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;

struct edge{
  ll cost; int u, v;
  edge(ll _cost, int _u, int _v) {
    cost = _cost; u = _u; v = _v;
  }
  bool operator< (const edge &n){
    return cost < n.cost;
  }
};

int main() {
  int n; cin >> n;
  vector<edge> es;
  rep(i, 0, n-1) rep(j, 0, n-1) {
    ll c; cin >> c;
    if(i >= j) continue;
    // cout << c << " " << i << " -> " << j << endl;
    es.push_back(edge(c, i, j));
  }
  sort(all(es));

  vector<vector<ll>> cost(n, vector<ll>(n, INF));
  rep(i, 0, n-1) cost[i][i] = 0;
  
  bool ng = false;
  ll ans = 0;
  for(auto e : es) {
    // cout << e.cost << " " << e.u << " -> " << e.v << endl;
    rep(k, 0, n-1) {
      if(e.cost > cost[e.u][k] + cost[k][e.v]){
        ng = true;
        break;
      }
    }if(ng) break;

    bool new_road = true;
    rep(k, 0, n-1) {
      if(e.cost == cost[e.u][k] + cost[k][e.v]){
        // cost[e.u][e.v] = e.cost;
        new_road = false;
        break;
      }
    }
    cost[e.u][e.v] = cost[e.v][e.u] = e.cost;
    // cout << e.cost << " " << e.u << " -> " << e.v << " ";
    // if(!new_road) cout << "reuse" << endl;
    // else cout << "new" << endl;
    if(new_road) ans += e.cost;
  }

  if(ng) cout << -1 << endl;
  else cout << ans << endl;
}