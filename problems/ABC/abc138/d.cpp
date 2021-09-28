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
const ll MOD = 1e9+7;
const ll INF = 1e18;

vector<bool> used(1000000, false);
vector<ll> cnt(200005, 0);

void dfs(int s, ll cur, vector<vector<int>> &to, vector<int> &x) {
  cnt[s] = cur + x[s];

  used[s] = true;
  for(auto v : to[s]) {
    if(used[v]) continue;
    dfs(v, cur+x[s], to, x);  
  }
  used[s] = false;
}

int main() {
  int n, q; cin >> n >> q;
  vector<vector<int>> to(n, vector<int>(0));
  vector<int> x(n+1, 0);

  rep(i, 0, n-2) {
    int a, b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  rep(i, 0, q-1) {
    int p, xx; cin >> p >> xx; p--;
    x[p] += xx;
  }

  dfs(0, 0, to, x);
  
  rep(i, 0, n-2) cout << cnt[i] << " ";
  cout << cnt[n-1] << endl;
}

