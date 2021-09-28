#include <bits/stdc++.h>
#include <atcoder/all>
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
// const ll INF = 1e16;
const int INF = 1001001001;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}
vector<vector<int>> len(2000, vector<int>(2000, INF));

struct Edge {
  int to, cost;
};

void dijkstra(int s, vector<vector<Edge>> &G) {
  int n = G.size();
  vector<int> d(n, INF);
  d[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.emplace(0, s);
  while(q.size()) {
    auto [cost, v] = q.top(); q.pop();
    if(d[v] < cost) continue;
    for(Edge e : G[v]) {
      if(chmin(d[e.to], d[v]+e.cost)) q.emplace(d[e.to], e.to);
    }
  }
  rep(i, 0, n-1) if(i != s) len[s][i] = d[i];
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<Edge>> G(n);
  rep(i, 0, m-1) {
    int a, b, c; cin >> a >> b >> c; a--, b--;
    if(a==b) chmin(len[a][a], c);
    else G[a].push_back((Edge){b, c});
  }

  rep(i, 0, n-1) dijkstra(i, G);
  
  rep(i, 0, n-1) {
    int ans = INF;
    chmin(ans, len[i][i]);
    rep(j, 0, n-1) if(i != j) chmin(ans, len[i][j] + len[j][i]);
    if(ans < INF) cout << ans << endl;
    else cout << -1 << endl;
  }
}