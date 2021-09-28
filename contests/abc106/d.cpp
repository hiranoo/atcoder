#include <bits/stdc++.h>
// #include <atcoder/segtree>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// const ll MOD = 1e9+7;
const ll INF = 1e18;

int main() {
  int n, m, q; cin >> n >> m >> q;
  vector<vector<int>> tail(n+1), head(n+1);
  rep(i, 0, m-1) {
    int a, b; cin >> a >> b;
    // a--; b--;
    tail[b].push_back(a);
    head[a].push_back(b);
  }

  // cout << endl;
  // rep(i, 1, n) {
  //   cout << i << ":" << endl;
  //   for(auto a : edge[i]) cout << a << " "; cout << endl;
  // }

  vector<int> sum(n+1, 0), minus(n+1, 0);
  rep(i, 1, n) sum[i] = sum[i-1] + tail[i].size();
  rep(i, 1, n) minus[i] = minus[i-1] + head[i].size();

  rep(i, 0, n) cout << i << " "; cout << endl;
  for(auto v : sum) cout << v << " "; cout << endl;
  for(auto v : minus) cout << v << " "; cout << endl;

  rep(i, 0, q-1) {
    int u, v; cin >> u >> v;
    cout << sum[v] - minus[u-1] << endl;
  }
}
