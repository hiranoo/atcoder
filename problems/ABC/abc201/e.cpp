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
const ll INF = 1e16;

struct Edge {
  int to; ll w;
};

vector<ll> tour;
vector<vector<Edge>> G(200005);
vector<bool> used(200005, false);
vector<ll> d(200005, 0);
void dfs(int u=0) {
  used[u] = true;

  for(auto e : G[u]) {
    if(used[e.to]) continue;
    d[e.to] = d[u]^e.w;
    dfs(e.to);
  }
}

int main() {
  int n; cin >> n;
  rep(i, 0, n-2) {
    int u, v; ll w; cin >> u >> v >> w; u--; v--;
    G[u].push_back((Edge){v, w});
    G[v].push_back((Edge){u, w});
  }

  dfs();
  
  ll ans = 0;
  rep(digit, 0, 59) {
    ll x = 0;
    rep(i, 0, n-1) if(d[i]>>digit & 1) x++;
    ll now = x * (n - x) % MOD;
    now = now * ((1LL<<digit)%MOD) % MOD;
    ans += now;
    ans %= MOD;
  }
  cout << (ans + MOD) % MOD << endl;
}