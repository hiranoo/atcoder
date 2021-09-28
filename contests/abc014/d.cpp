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
// const ll INF = 1e18;
const int INF = 1001001001;

vector<int> bfs(vector<vector<int>> &G) {
  int n = G.size();
  vector<int> d(n, -1);
  queue<int> q;
  q.push(0);
  d[0] = 0;
  while(q.size()) {
    int v = q.front(); q.pop();
    for(auto nv : G[v]) {
      if(d[nv] == -1) {
        q.push(nv);
        d[nv] = d[v] + 1;
      }
    }
  }
  return d;
}

void dfs(int u, vector<vector<int>> &G, vector<bool> &used, vector<int> &path) {
  used[u] = true;
  path.push_back(u);
  for(auto v : G[u]) {
    if(!used[v]) {
      dfs(v, G, used, path);
      path.push_back(u);
    }
  }
}

int op(int a, int b) {
  return min(a, b);
}

int e() {
  return INF;
}

int main() {
  int n; cin >> n;
  vector<vector<int>> G(n);
  rep(i, 0, n-2) {
    int x, y; cin >> x >> y; x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  vector<int> dis = bfs(G);

  // lca
  vector<int> path;
  vector<bool> used(n, false);
  dfs(0, G, used, path);

  int len = path.size();
  vector<int> dep(len);
  rep(i, 0, len-1) dep[i] = dis[path[i]];

  atcoder::segtree<int, op, e> seg(dep);
  vector<int> order(n, -1);
  rep(i, 0, len-1) {
    int j = path[i];
    if(order[j] == -1) order[j] = i;
  }

  int q; cin >> q;
  rep(i, 0, q-1) {
    int a, b; cin >> a >> b; a--; b--;
    if(order[a] > order[b]) swap(a, b);
    int res = seg.prod(order[a], order[b]+1);   
    cout << dis[a] + dis[b] - 2 * res + 1 << endl;
  }
  // for(auto v : path) cout << v << " "; cout << endl;
}