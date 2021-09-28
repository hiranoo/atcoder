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
// const ll INF = 1e18;


int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n);
  rep(i, 0, m-1) {
    int a, b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  const int INF = 1001001001;
  vector<int> d(n, INF);
  d[0] = 0;
  queue<int> que;
  que.push(0);
  while(que.size()) {
    int u = que.front(); que.pop();
    
    for(auto v : to[u]) {
      if(d[v] < INF) continue;
      que.push(v);
      d[v] = d[u]+1;
    }
  }

  bool ok = true;
  for(auto v : d) if(v==INF) ok = false;
  if(!ok) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  rep(u, 1, n-1) {
    for(auto v : to[u]) {
      if(d[v] == d[u] -1) {
        cout << v+1 << endl;
        break;
      }
    }
  }
}