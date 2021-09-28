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

vector<bool> used(300000, false);
vector<int> ans;

void dfs(int v, vector<vector<int>> &E) {
  ans.push_back(v);
  used[v] = true;

  for(auto to : E[v]) {
    if(used[to]) continue;
    dfs(to, E);
    ans.push_back(v);
  }
}

int main() {
  int n; cin >> n;
  vector<vector<int>> E(n+1, vector<int>(0));
  rep(i, 0, n-2) {
    int a, b; cin >> a >> b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  rep(i, 0, n) sort(all(E[i]));

  dfs(1, E);
  for(ll i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if(i == ans.size() -1) cout << endl;
    else cout << " ";
  }
}