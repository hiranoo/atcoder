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

void dfs(int v, vector<vector<int>> &G, vector<bool> &used, vector<int> &vs) {
  used[v] = true;
  for(auto u : G[v]) {
    if(!used[u]) dfs(u, G, used, vs);
  }
  vs.push_back(v);
}

void rdfs(int v, vector<vector<int>> &rG, vector<bool> &used, vector<int> &cmp, int k) {
  used[v] = true;
  cmp[v] = k;
  for(auto u : rG[v]) if(!used[u]) rdfs(u, rG, used, cmp, k);
}

vector<int> scc(vector<vector<int>> &G, vector<vector<int>> &rG) {
  int n = G.size();
  vector<bool> used(n, false);
  vector<int> vs;
  
  rep(v, 0, n-1) if(!used[v]) dfs(v, G, used, vs);
  rep(i, 0, n-1) used[i] = false;
  
  reverse(all(vs));
  vector<int> cmp(n);
  int k = 0;
  for(auto v : vs) {
    if(!used[v]) rdfs(v, rG, used, cmp, k++);
  }
  return cmp;
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n), rG(n);
  rep(i, 0, m-1) {
    int from, to; cin >> from >> to;
    from--; to--;
    G[from].push_back(to);
    rG[to].push_back(from);
  }

  vector<int> cmp = scc(G, rG);
  int max_cmp = -1;
  int max_v = -1;
  int max_size = 0;
  rep(i, 0, n-1) {
    if(max_cmp < cmp[i]) {
      max_cmp = cmp[i];
      max_v = i;
      max_size = 1;
    }else if(max_cmp == cmp[i]) {
      max_size++;
    }
  }

  vector<bool> used(n, false);
  vector<int> tmp(n);
  rdfs(max_v, rG, used, tmp, 0);
  for(auto v : used) {
    if(!v) {
      cout << 0 << endl;
      return 0;
    }
  }

  cout << max_size << endl;
}