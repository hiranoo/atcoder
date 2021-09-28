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
const int MAX_N = 100005;
template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int n;
vector<int> c(MAX_N);
vector<vector<int>> to(MAX_N);
vector<bool> used(MAX_N, false);
vector<int> cnt(MAX_N, 0);
vector<bool> good(MAX_N, false);

void dfs(int u) {
  used[u] = true;
  if(cnt[c[u]]==0) good[u] = true;
  cnt[c[u]]++;
  for(int v : to[u]) {
    if(used[v]) continue;
    dfs(v);
  }
  cnt[c[u]]--;
}


int main() {
  cin >> n;
  rep(i, 0, n-1) cin >> c[i];
  rep(i, 0, n-2) {
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v);
    to[v].push_back(u);
  }

  dfs(0);
  rep(i, 0, n-1) if(good[i]) cout << i+1 << endl;
}