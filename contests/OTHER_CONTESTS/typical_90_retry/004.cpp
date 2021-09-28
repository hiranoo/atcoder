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

vector<int> bfs(int s, vector<vector<int>> &to) {
  int n = to.size();
  vector<int> d(n, -1);
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while(q.size()) {
    int u = q.front(); q.pop();
    for(auto v : to[u]) {
      if(d[v] != -1) continue;
      q.push(v);
      d[v] = d[u] + 1;
    }
  }

  return d;
}

int main() {
  int h, w; cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, 0, h-1) rep(j, 0, w-1) cin >> a[i][j];
  
  vector<int> sr(h, 0), sc(w, 0);
  rep(i, 0, h-1) rep(j, 0, w-1) sr[i] += a[i][j];
  rep(j, 0, w-1) rep(i, 0, h-1) sc[j] += a[i][j];

  rep(i, 0, h-1) {
    rep(j, 0, w-1) cout << (j==0? "": " ") << sr[i]+sc[j]-a[i][j];
    cout << endl;
  }
}