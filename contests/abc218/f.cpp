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

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

void solve1() {
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n), from(n);
  vector<pii> edge(m);
  rep(i, 0, m-1) {
    int s, t; cin >> s >> t; s--, t--;
    to[s].push_back(t);
    from[t].push_back(s);
    edge[i] = pii(s, t);
  }
  sort(all(edge));

  const int INF = 1001001001;
  queue<int> q;
  q.push(0);
  vector<int> d1(n, INF), d2(n, INF);
  vector<vector<int>> ds1(n), ds2(n);
  d1[0] = 0;
  d2[n-1] = 0;

  while(q.size()) {
    int v = q.front(); q.pop();
    for(int nv : to[v]) {
      if(d1[nv] <= d1[v] + 1) continue;
      q.push(nv);
      d1[nv] = d1[v] + 1;
      ds1[nv] = ds1[v];
      int edge_id = lower_bound(all(edge), pii(v, nv)) - edge.begin();
      ds1[nv].push_back(edge_id);
      // if(nv == n-1) break;
    }
  }
  while(q.size()) q.pop();

  q.push(n-1);
  while(q.size()) {
    int v = q.front(); q.pop();
    for(int nv : from[v]) {
      // cout << nv << " <-" << v << endl;
      if(d2[nv] <= d2[v] + 1) continue;
      q.push(nv);
      d2[nv] = d2[v] + 1;
      ds2[nv] = ds2[v];
      int edge_id = lower_bound(all(edge), pii(nv, v)) - edge.begin();
      ds2[nv].push_back(edge_id);
      // if(nv == 0) break;
    }
  }

  rep(i, 0, n-1) {
    sort(all(ds1[i])); //ds1[i].push_back(INF);
    sort(all(ds2[i])); //ds2[i].push_back(INF);
  }

  rep(i, 0, n-1) {
    ds1[i].push_back(INF);
    ds2[i].push_back(INF);
  }

  rep(i, 0, m-1) {
    int ans = INF;
    rep(j, 0, n-1) {
      if(*lower_bound(all(ds1[j]), i)==i || *lower_bound(all(ds2[j]), i)==i) continue;
      if(d1[j] == INF || d2[j] == INF) continue;
      chmin(ans, d1[j] + d2[j]);
    }
    if(ans < INF) cout << ans << endl;
    else cout << -1 << endl;
  }
}

void solve2() {
  int n, m; cin >> n >> m;
  map<pii, int> edge;
  vector<vector<int>> to(n);
  rep(i, 0, m-1) {
    int s,t; cin >> s >> t; s--, t--;
    edge[pii(s, t)] = i;
    to[s].push_back(t);
  }

  const int INF = 1001001001;
  auto bfs = [&] (int ng) {
    vector<int> d(n, INF);
    d[0] = 0;
    vector<vector<int>> s(n);
    queue<int> q;
    q.push(0);
    while(q.size()) {
      int v = q.front(); q.pop();
      for(int u : to[v]) {
        if(d[u] <= d[v]+1) continue;
        if(ng >= 0 && edge[pii(v, u)] == ng) continue;
        q.push(u);
        d[u] = d[v] + 1;
        s[u] = s[v];
        int e = edge[pii(v, u)];
        s[u].push_back(e);
        if(u == n-1) break;
      }
    }
    return make_pair(d, s[n-1]);
  };
    
  auto [d0, s0] = bfs(-1);
  sort(all(s0));
  s0.push_back(INF);
  rep(i, 0, m-1) {
    if(*lower_bound(all(s0), i) != i) {
      if(d0[n-1] < INF) cout << d0[n-1] << endl;
      else cout << -1 << endl;
      continue;
    }

    auto [d, s] = bfs(i);
    if(d[n-1] < INF) cout << d[n-1] << endl;
    else cout << -1 << endl;      
  }
}

int main() {
  // solve1();
  solve2();
}