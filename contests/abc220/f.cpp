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
const int MAX_N = 200005;
int n;
vector<vector<int>> to(MAX_N);
vector<ll> ans(MAX_N, 0);
vector<bool> used(MAX_N, false);
vector<int> children(MAX_N, 0);

void dfs(int u, int dep) {
  used[u] = true;
  ans[0] += dep;
  for(auto v : to[u]) {
    if(used[v]) continue;
    dfs(v, dep+1);
    children[u]++;
  }
}

int count_children(int u) {
  used[u] = true;
  int res = 1;
  for(auto ch : to[u]) {
    if(used[ch]) continue;
    res += count_children(ch);
  }
  return children[u] = res;
}

void f(int u) {
  used[u] = true;
  for(auto ch : to[u]) {
    if(used[ch]) continue;
    ans[ch] = ans[u] + n - 2*(children[ch]);
    f(ch);
  }
}

int main() {
  cin >> n;
  to.resize(n);
  rep(i, 0, n-2) {
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v);
    to[v].push_back(u);
  }

  dfs(0, 0);

  children = vector<int>(n, 0);
  rep(i, 0, n-1) used[i] = false;
  count_children(0);

  rep(i, 0, n-1) used[i] = false;  
  f(0);
  rep(i, 0, n-1) cout << ans[i] << endl;
}