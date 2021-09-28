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
const ll INF = 1e18;

void dfs(int v, vector< vector<int> > &G, vector<bool> &used, vector<int> &tp) {
  used[v] = true;
  for(auto u : G[v]) {
    if(used[u]) continue;
    dfs(u, G, used, tp);
  }
  tp.push_back(v);
}

void rdfs(int v, vector< vector<int> > &rG, vector<bool> &used, vector<int> &group, int k) {
  used[v] = true;
  group[v] = k;
  for(auto u : rG[v]) {
    if(used[u]) continue;
    rdfs(u, rG, used, group, k);
  }
}

vector<int> scc(vector< vector<int> > &G, vector< vector<int> > &rG) {
  int n = G.size();
  vector<int> ans(n), tp;
  
  vector<bool> used(n, false);
  int k = 0;
  rep(i, 0, n-1) if(!used[i]) dfs(i, G, used, tp);

  rep(i, 0, n-1) used[i] = false;
  k = 0;
  for(int i = n-1; i >= 0; i--) if(!used[tp[i]]) rdfs(tp[i], rG, used, ans, k++);
  return ans;
}

int main() {
  int n, m; cin >> n >> m;
  vector< vector<int> > G(n), rG(n);
  rep(i, 0, m-1) {
    int s, t; cin >> s >> t;
    G[s].push_back(t);
    rG[t].push_back(s);
  }

  vector<int> vec = scc(G, rG);

  int q; cin >> q;
  rep(i, 0, q-1) {
    int u, v; cin >> u >> v;
    if(vec[u] == vec[v]) cout << 1 << endl;
    else cout << 0 << endl;
  }
}