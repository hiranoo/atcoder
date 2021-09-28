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
const int INF = 1001001001;

struct Edge {
  int to, id;
};

vector<vector<Edge>> G;
vector<int> ans;
void dfs(int u=0, int p=-1, int c=-1) {
  int k = 1;
  for(auto e : G[u]) {
    int v = e.to, ei = e.id;
    if(v == p) continue;
    if(k == c) k++;
    ans[ei] = k++;
    dfs(v, u, ans[ei]);
  }
} 

void bfs() {
  int n = G.size();
  queue<pii> q;
  q.push(pii(0, -1));
  vector<bool> used(n, false);
  vector<int> par(n);
  par[0] = -1;

  while(q.size()) {
    pii p = q.front(); q.pop();
    int u = p.first, pre_c = p.second;
    used[u] = true;

    int k = 1;  
    for(auto e : G[u]) {
      int v = e.to, ei = e.id;
      // if(v == par[u]) continue;
      if(used[v]) continue;
      if(k == pre_c) k++;
      ans[ei] = k++;
      q.push(pii(v, ans[ei]));
    }
  }
}

int main() {
  int n; cin >> n;
  G.resize(n);
  ans.resize(n-1);
  rep(i, 0, n-2) {
    int a, b; cin >> a >> b; a--; b--;
    G[a].push_back((Edge){b, i});
    G[b].push_back((Edge){a, i});
  }

  // dfs();
  bfs();

  int ma = 0;
  for(auto v : ans) ma = max(v, ma);
  cout << ma << endl;
  for(auto v : ans) cout << v << endl;
}