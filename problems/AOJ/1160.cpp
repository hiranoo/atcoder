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

int dx[8] = {1, -1, 1, -1, 0, 1, -1, 0};
int dy[8] = {0, 0, 1, 1, 1, -1, -1, -1};

void dfs(vector< vector<int> > &c, vector< vector<int> > &used, int sx, int sy) {
  int h = c.size(), w = c[0].size();
  used[sy][sx] = 1;

  rep(i, 0, 7) {
    int nx = sx + dx[i], ny = sy + dy[i];
    if(nx < 0 || w<=nx || ny<0 || h<= ny) continue;
    if(used[ny][nx]) continue;
    if(c[ny][nx] == 0) continue;
    dfs(c, used, nx, ny);
  }
}

int _main() {
  int w, h; cin >> w >> h;
  if(w==0 && h==0) return -1;
  vector< vector<int> > c(h, vector<int>(w)), used(h, vector<int>(w, 0));
  rep(y, 0, h-1) rep(x, 0, w-1) cin >> c[y][x];

  int ans = 0;
  rep(y, 0, h-1) rep(x, 0, w-1) {
    if(c[y][x]==0) continue;
    if(used[y][x]==0) ans++;
    dfs(c, used, x, y);
  }
  cout << ans << endl;
  return 0;
}

int main() {
  while(1) {
    int i = _main();
    if(i==-1) break;
  }
}