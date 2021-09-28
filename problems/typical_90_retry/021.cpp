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
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e16;

void dfs(int u, vector<bool> &used, vector<int> &vs, vector<vector<int>> &G) {
  used[u] = true;
  for(auto v : G[u]) {
    if(!used[v]) dfs(v, used, vs, G);
  }
  vs.push_back(u);
}

void rdfs(int u, vector<bool> &used, vector<vector<int>> &rG, vector<int> &cmp, int k) {
  used[u] = true;
  cmp[u] = k;
  for(auto v : rG[u]) {
    if(!used[v]) rdfs(v, used, rG, cmp, k);
  }
}

ll scc(vector<vector<int>> &G, vector<vector<int>> &rG) {
  int n = G.size();
  vector<int> vs;
  vector<bool> used(n, false);
  rep(i, 0, n-1) if(!used[i]) dfs(i, used, vs, G);
  reverse(all(vs));
  rep(i, 0, n-1) used[i] = false;
  vector<int> cmp(n);
  int k = 0;
  for(auto i : vs) if(!used[i]) rdfs(i, used, rG, cmp, k++);

  vector<int> sz(k, 0);
  for(auto g : cmp) sz[g]++;
  ll ans = 0;
  for(auto v : sz) ans += (ll)v*(v-1)/2;
  return ans;
}


// void dfs(int v, vector<vector<int>> &G, vector<bool> &used, vector<int> &vs) {
//   used[v] = true;
//   for(auto u : G[v]) {
//     if(!used[u]) dfs(u, G, used, vs);
//   }
//   vs.push_back(v);
// }

// void rdfs(int v, vector<vector<int>> &rG, vector<bool> &used, vector<int> &cmp, int k) {
//   used[v] = true;
//   cmp[v] = k;
//   for(auto u : rG[v]) if(!used[u]) rdfs(u, rG, used, cmp, k);
// }

// vector<int> scc(vector<vector<int>> &G, vector<vector<int>> &rG) {
//   int n = G.size();
//   vector<bool> used(n, false);
//   vector<int> vs;
  
//   rep(v, 0, n-1) if(!used[v]) dfs(v, G, used, vs);
//   rep(i, 0, n-1) used[i] = false;
  
//   reverse(all(vs));
//   vector<int> cmp(n);
//   int k = 0;
//   for(auto v : vs) if(!used[v]) rdfs(v, rG, used, cmp, k++);
//   return cmp;
// }


int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n), rG(n);
  map<pii, int> edge;
  rep(i, 0, m-1) {
    int a, b; cin >> a >> b; a--; b--;
    edge[pii(a, b)]++;
    if(edge[pii(a, b)] == 1) {
      G[a].push_back(b);
      rG[b].push_back(a);
    }
  }

  // vector<int> cmp = scc(G, rG);
  // ll ans = 0;
  // vector<int> g(n);
  // for(int i : cmp) g[i]++;
  // for(int i : g) ans += (ll)i * (i-1) / 2;
  // cout << ans << endl;
  cout << scc(G, rG) << endl;
}