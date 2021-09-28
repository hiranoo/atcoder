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

bool chmax(ll &a, ll b) {if(a < b) {a = b; return true;} return false;}
bool chmin(ll &a, ll b) {if(a > b) {a = b; return true;} return false;}

int dfs(int v, vector<vector<int>> &to, vector<bool> &used, vector<int> &dp) {
  used[v] = true;
  int fans = 1;
  for(auto nv : to[v]) {
    if(!used[nv]) fans += dfs(nv, to, used, dp);
  }
  return dp[v] = fans;
}

int main() {
  int n; cin >> n;
  vector<vector<int>> to(n);
  rep(i, 0, n-2) {
    int a, b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  vector<int> dp(n, 0);
  vector<bool> used(n, false);

  dfs(0, to, used, dp);

  ll ans = 0;
  rep(u, 0, n-1) ans += (ll) dp[u] * (n - dp[u]);
  cout << ans << endl;
}