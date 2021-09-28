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

void dfs(int v, vector<int> &tp, vector<vector<int>> &G, vector<bool> &used) {
  used[v] = true;
  for(auto u : G[v]) {
    if(!used[u]) dfs(u, tp, G, used);
  }
  tp.push_back(v);
}

bool contain(vector<vector<int>> &G, int a, int b) {
  // cout << a << " "<< b << endl;
  if(G[a].size() && b==*lower_bound(all(G[a]), b)) return true;
  if(G[b].size() && a==*lower_bound(all(G[b]), a)) return true;
  return false;
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, 0, m-1) {
    int a, b; cin >> a >> b; a--; b--;
    G[a].push_back(b);
  }
  rep(i, 0, n-1) sort(all(G[i]));

  vector<bool> used(n, false);
  vector<int> tp;
  for(int v = 0; v < n; v++) {
    if(!used[v]) dfs(v, tp, G, used);
  }
  reverse(all(tp));
  int ans = 0;
  rep(i, 0, n-2) {
    if(!contain(G, tp[i], tp[i+1])) {
      ans = 1;
      break;
    }
  }

  rep(j, 0, n-1) cout << tp[j]+1 << endl;
  cout << ans << endl;
}