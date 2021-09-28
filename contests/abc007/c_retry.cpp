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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
  int n, m; cin >> n >> m;
  int sx, sy, gx, gy;
  cin >> sy >> sx >> gy >> gx;
  sy--;sx--;gy--;gx--;

  vector<string> a(n);
  rep(i, 0, n-1) cin >> a[i];

  vector<vector<int>> dep(n, vector<int>(m, -1));
  dep[sy][sx] = 0;
  queue<pii> que;
  que.push(pii(sx, sy));
  while(que.size()) {
    pii p = que.front(); que.pop();
    int x = p.first, y = p.second;
    
    if(x==gx && y==gy) break;

    rep(i, 0, 3) {
      int nx = x+dx[i], ny=y+dy[i];
      if(a[ny][nx] == '#') continue;
      if(dep[ny][nx] != -1) continue;
      dep[ny][nx] = dep[y][x]+1;
      que.push(pii(nx, ny));
    }
  }

  cout << dep[gy][gx] << endl;
}