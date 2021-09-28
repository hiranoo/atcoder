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
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

const int MAX_V = 200005;
vector<int> to[MAX_V];
vector<int> query[MAX_V];
vector<int> cnt(MAX_V, 0);
map<pii, int> mp, ans;
vector<bool> done(MAX_V, false);




int main() {
  int n; cin >> n;
  rep(i, 1, n-1) {
    int p; cin >> p; p--;
    to[p].push_back(i);
  }

  int q; cin >> q;
  while(q--) {
    int u, d; cin >> u >> d; u--;
    query[u].push_back(d);
  }
  dfs(0, 0);
}
// vector<vector<int>> to(MAX_V);
// int dep[MAX_V];
// int in[MAX_V];
// int out[MAX_V];
// int k = 0;
// vector<int> lis[MAX_V];

// void dfs(int v, int d) {
//   in[v] = k++;
//   dep[v] = d;
//   for(auto u : to[v]) {
//     dfs(u, d+1);
//   }
//   out[v] = k;
// }

// int main() {
//   int n; cin >> n;
//   rep(i, 1, n-1) {
//     int p; cin >> p;
//     to[p-1].push_back(i);
//   }
  
//   dfs(0, 0);
//   rep(i, 0, n-1) lis[dep[i]].push_back(in[i]);
//   rep(i, 0, n-1) sort(all(lis[i]));
//   int q; cin >> q;

//   auto f = [&] (int d, int r) {
//     return (int)(lower_bound(all(lis[d]), r) - lis[d].begin());
//   };

//   while(q--) {
//     int u, d; cin >> u >> d; u--;
//     int ans = f(d, out[u]) - f(d, in[u]);
//     cout << ans << endl;
//   }
// }