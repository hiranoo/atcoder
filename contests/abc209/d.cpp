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
const int INF = 1000000007;

void dfs(vector<vector<int>> &G, vector<int> &dep) {
  int n = G.size();
  stack<pii> stk;
  stk.push(pii(0, 0));
  vector<bool> used(n, false);
  while(stk.size()) {
    pii p = stk.top(); stk.pop();
    int v = p.first;
    int d = p.second;

    used[v] = true;
    dep[v] = d;

    for(auto nv : G[v]) {
      if(!used[nv]) stk.push(pii(nv, d+1));
    }
  }
}

void dfs(vector<vector<int>> &G, vector<int> &dep, int v, int _dep=0) {
  if(dep[v] != -1) return;

  dep[v] = _dep;
  for(auto nv : G[v]) {
    dfs(G, dep, nv, _dep+1);
  }
}

int main(){
  int n, q; cin >> n >> q;
  vector<vector<int>> G(n, vector<int>(0));
  rep(i, 0, n-2) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  // dfs
  vector<int> dep(n, -1);
  dfs(G, dep, 0, 0);
  rep(i, 0, q-1) {
    int c, d; cin >> c >> d; c--; d--;
    if ((dep[c] + dep[d]) % 2 == 0) cout << "Town" << endl;
    else cout << "Road" << endl;
  }


  // // djikstra
  // vector<int> dis(n, INF);
  // dis[0] = 0;
  // priority_queue<pii> que;
  // que.push(pii(0, 0));
  // while(que.size()){
  //   pii p = que.top(); que.pop();
  //   int v = p.first;
  //   int d = p.second;
  //   if(dis[v] < d) continue;
  //   for(int i = 0; i < G[v].size(); i++) {
  //     int nv = G[v][i];
  //     if(dis[nv] > dis[v] + 1) {
  //       dis[nv] = dis[v] + 1;
  //       que.push(pii(nv, dis[nv]));
  //     }
  //   }
  // }

  // rep(i, 0, q-1) {
  //   int c, d; cin >> c >> d;
  //   c--; d--;
  //   if((dis[d]-dis[c]) % 2 == 0) cout << "Town" << endl;
  //   else cout << "Road" << endl;
  // }
}