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
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e16;

void dfs(int u, int dep, vector<int> &d, vector<vector<int>> &to) {
  d[u] = dep;
  for(int v : to[u]) {
    if(d[v] == -1) dfs(v, dep+1, d, to);
  }
}


int main() {
  int n; cin >> n;
  vector<vector<int>> to(n);
  rep(i, 1, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  vector<int> d(n, -1);

  dfs(0, 0, d, to);

  int cnt = 0;
  vector<int> a, b;
  rep(i, 0, n-1) if(d[i]%2==0) a.push_back(i); else b.push_back(i);

  if(a.size() >= b.size()) {
    rep(i, 0, n/2 - 1) cout << (i==0? "" : " ") << a[i]+1; cout << endl;
  }else{
    rep(i, 0, n/2 - 1) cout << (i==0? "" : " ") << b[i]+1; cout << endl;
  }
}