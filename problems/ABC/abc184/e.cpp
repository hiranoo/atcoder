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

struct P {
  int y, x;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
  int h, w; cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h-1) cin >> a[i];
  vector<vector<P>> s(26);
  P start, goal;
  rep(i, 0, h-1) rep(j, 0, w-1) {
    if('a' <= a[i][j] && a[i][j] <= 'z') {
      int c = a[i][j] - 'a';
      s[c].push_back((P){i, j});
    }else if(a[i][j] == 'S') {
      start = (P){i, j};
    }else if(a[i][j] == 'G') {
      goal = (P){i, j};
    }
  }

  vector<vector<ll>> d(h, vector<ll>(w, INF));
  vector<bool> used(26, false);
  d[start.y][start.x] = 0;
  queue<P> q;
  q.push(start);
  while(q.size()) {
    P p = q.front(); q.pop();

    if(p.y == goal.y && p.x == goal.x) break;
    rep(i, 0, 3) {
      int ny = p.y + dy[i], nx = p.x + dx[i];
      if(ny<0 || ny>=h || nx<0 || nx>=w || a[ny][nx]=='#') continue;
      if(d[ny][nx] > d[p.y][p.x] + 1) {
        q.push((P){ny, nx});
        d[ny][nx] = d[p.y][p.x] + 1;
      }
    }
    if('a' <= a[p.y][p.x] && a[p.y][p.x] <= 'z') {
      int c = a[p.y][p.x] - 'a';
      if(used[c]) continue;
      used[c] = true;
      for(auto v : s[c]) {
        if(d[v.y][v.x] > d[p.y][p.x] + 1) {
          q.push((P){v.y, v.x});
          d[v.y][v.x] = d[p.y][p.x] + 1;
        }
      }
    }
  }

  if(d[goal.y][goal.x] < INF) cout << d[goal.y][goal.x] << endl;
  else cout << -1 << endl;
}