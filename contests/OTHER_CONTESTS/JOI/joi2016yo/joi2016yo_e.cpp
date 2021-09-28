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

vector<ll> dijkstra(int s, vector< map<int, ll> > &G, vector<bool> zombi, vector<bool> dangered, ll q) {
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
      if(zombi[to]) continue;
      if(to != n-1 && dangered[to]) cost = q;
      if(d[to] > d[v] + cost){
        d[to] = d[v] + cost;
        que.push(P(d[to], to));
      }
    }
  }
  return d;
}

vector<int> bfs(int s, vector< vector<int> > &to, int n, int LIMIT) {
  queue<pii> que;
  que.push(pii(0, s));
  vector<int> dangered;
  vector<bool> used(n+1, false);
  while(que.size()) {
    pii p = que.front(); que.pop();
    int dep = p.first;
    int v = p.second;
    
    if(used[v]) continue;
    if(dep > LIMIT) continue;
    used[v] = true;

    for(auto nv : to[v]) {
      if(used[nv]) continue;
      que.push(pii(dep+1, nv));
    }
  }
  rep(i, 0, n-1) if(used[i]) dangered.push_back(i);
  return dangered;
}

int main() {
  int n, m, k, s; cin >> n >> m >> k >> s;
  ll p, q; cin >> p >> q;

  map<int, ll> mp; // key=頂点, value=コスト
  vector< map<int, ll> > G(n, map<int, ll>(mp));
  vector< vector<int> > to(n+1, vector<int>(0));
  vector<int> zombi(k), dangered;

  rep(i, 0, k-1) {
    cin >> zombi[i]; zombi[i]--;
    to[n].push_back(zombi[i]);
  }
  rep(i, 0, m-1) {
    int a, b; cin >> a >> b; a--; b--;
    G[a][b] = p;
    G[b][a] = p;
    to[a].push_back(b);
    to[b].push_back(a);
    if(a==n-1) G[b][a] = 0;
    if(b==n-1) G[a][b] = 0;
  }

  dangered = bfs(n, to, n, s+1);

  vector<bool> zombi_flag(n, false), dangered_flag(n, false);
  for(auto z : zombi) zombi_flag[z] = true;
  for(auto d : dangered) dangered_flag[d] = true;
  // for(auto dd : dangered) cout << "dangered:" << dd+1 << endl;

  // rep(u, 0, n-1) rep(v, 0, n-1) {
  //   if(G[u].count(v)>0) cout << u+1 << "->" << v+1 << ": " << G[u][v] << endl;
  // }

  vector<ll> dis = dijkstra(0, G, zombi_flag, dangered_flag, q);
  cout << dis[n-1] << endl;
}

