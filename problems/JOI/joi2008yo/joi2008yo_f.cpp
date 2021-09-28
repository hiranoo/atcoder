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
typedef pair<ll, int> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;

//   map<int, ll> mp; // key=頂点, value=コスト
//   vector<map<int, ll>> G(n, map<int, ll>(mp)); 

vector<ll> dijkstra(int s, vector< map<int, ll> > &G) {
  priority_queue< P, vector<P>, greater<P> > que;
  que.push(P(0, s));
  int n = G.size();
  vector<ll> d(n, INF);
  d[s] = 0;
  
  while(que.size()) {
    P p = que.top(); que.pop();
    int v = p.second;

    if(d[v] < p.first) continue;
    
    for(auto itr = G[v].begin(); itr != G[v].end(); itr++) {
      int to = itr->first;
      ll cost = itr->second;
      if(d[to] > d[v] + cost){
        d[to] = d[v] + cost;
        que.push(P(d[to], to));
      }
    }
  }
  return d;
}

int main() {
  int n, k; cin >> n >> k;
  map<int, ll> mp;
  vector<map<int, ll>> es(n, map<int, ll>(mp));

  rep(query, 0, k-1) {
    int order; cin >> order;
    if(order) {
      int c, d; ll e; cin >> c >> d >> e; c--; d--;
      //cout << "debug: es[c][d]=" << es[c][d] << ", e=" << e << " -> ";
      if(es[c].count(d) == 0) {
        es[c][d] = e; es[d][c] = e;
      }else if(es[c][d] > e) {
        es[c][d] = es[d][c] = e;
      }
    }else{
      int a, b; cin >> a >> b; a--; b--;
      ll ans = dijkstra(a, b, es);
      if(ans == INF) cout << -1 << endl;
      else cout << ans << endl;
    }

    // cout << "query id: " << query << endl;
  }
}