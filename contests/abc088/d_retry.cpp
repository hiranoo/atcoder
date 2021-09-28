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

struct P {
  int x, y;
  P(){}
  P(int x, int y) : x(x), y(y) {}
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
  int h, w; cin >> h >> w;
  vector<string> a(h);
  rep(y, 0, h-1) cin >> a[y];

  queue<P> que;
  que.push(P(0, 0));
  vector<vector<int>> d(h, vector<int>(w, -1));
  d[0][0] = 0;

  while(que.size()) {
    P p = que.front(); que.pop();
    if(p.x==w-1 && p.y==h-1) break;

    rep(i, 0, 3) {
      int nx = p.x + dx[i];
      int ny = p.y + dy[i];
      if(nx<0 || ny<0 || w<=nx || h<=ny) continue;
      if(a[ny][nx] == '#') continue;
      if(d[ny][nx] != -1) continue;
      que.push(P(nx, ny));
      d[ny][nx] = d[p.y][p.x] + 1;
    }
  }

  int sum = 0;
  rep(y, 0, h-1) rep(x, 0, w-1) if(a[y][x] == '#') sum++;
  // cout << d[h-1][w-1] << endl;

  if(d[h-1][w-1] == -1) cout << -1 << endl;
  else cout << h*w - d[h-1][w-1] - 1 - sum << endl;
}