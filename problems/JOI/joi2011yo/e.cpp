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

int bfs(vector<vector<int>> &area, pii s, pii g) {
  int n = area.size(), m = area[0].size();
  
  queue<pii> que;
  que.push(pii(s));
  vector<vector<int>> d(n, vector<int>(m, -1));
  d[s.second][s.first] = 0;
  while(que.size()) {
    pii p = que.front(); que.pop();
    int x = p.first, y = p.second;
    if(x==g.first && y==g.second) break;
    rep(i, 0, 3) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx<0 || m<=nx || ny<0 || n<=ny) continue;
      if(area[ny][nx] == -1) continue;
      if(d[ny][nx] != -1) continue;
      que.push(pii(nx, ny));
      d[ny][nx] = d[y][x]+1;
    }
  } 
  return d[g.second][g.first];
}

int main() {
  int h, w, n; cin >> h >> w >> n;
  vector<string> a(h);
  rep(i, 0, h-1) cin >> a[i];

  vector<vector<int>> area(h, vector<int>(w, 0));
  vector<pii> s(n+1);
  
  // cout << 111 << endl;

  rep(y, 0, h-1) rep(x, 0, w-1) {
    switch(a[y][x]) {
      case 'X':
        area[y][x] = -1;
        break;
      case '.':
        break;
      case 'S':
        s[0] = pii(x, y);
        break;
      default:
        int num = a[y][x] - '0';
        s[num] = pii(x, y);
    }
  }

  // cout << 222 << endl;

  int ans = 0;
  rep(i, 0, n-1) ans += bfs(area, s[i], s[i+1]);
  cout << ans << endl;
}