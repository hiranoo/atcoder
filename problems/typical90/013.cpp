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
const int INF = 1000000005;

struct edge {
  int to, cost;
};

vector<int> dijkstra(vector<vector<edge>> &G, int n, int s){
  vector<int> d(n, INF);
  d[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> que; // dis, node
  que.push(pii(0, s));

  while(que.size()){
    pii p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(auto e : G[v]){
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(pii(d[e.to], e.to));
      }
    }
  }
  return d;
}

int main(){
  int n, m; cin >> n >> m;
  vector<vector<edge>> G(n, vector<edge>(0));
  rep(i, 0, m-1){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    G[a].push_back((edge){b, c}); // node, cost
    G[b].push_back((edge){a, c});
  }

  vector<int> d1 = dijkstra(G, n, 0);
  vector<int> d2 = dijkstra(G, n, n-1);
  rep(k, 0, n-1){
    cout << d1[k] + d2[k] << endl;
  }
}