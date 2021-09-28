#include <bits/stdc++.h>
#include <atcoder/all>
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
// const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

struct P {
  int x, y, dir;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  int h, w; cin >> h >> w;
  int sx, sy, gx, gy;
  cin >> sy >> sx >> gy >> gx;
  sy--, sx--, gy--, gx--;

  vector<string> a(h);
  rep(i, 0, h-1) cin >> a[i];

  const int INF = 1001001001;

  vector<vector<vector<int>>> d(h, vector<vector<int>>(w, vector<int>(4, INF)));
  
  deque<P> q;
  rep(i, 0, 3) {
    d[sy][sx][i] = 0;
    q.push_front((P){sx, sy, i});
  }
  while(q.size()) {
    P p = q.front(); q.pop_front();
    rep(i, 0, 3) {
      int nx = p.x + dx[i], ny = p.y + dy[i];
      if(ny<0 || nx<0 || ny>=h || nx>=w || a[ny][nx]=='#') continue;
      int cost = d[p.y][p.x][p.dir] + (i==p.dir? 0 : 1);
      if(d[ny][nx][i] > cost) {
        d[ny][nx][i] = cost;
        if(i==p.dir) q.push_front((P){nx, ny, i});
        else q.push_back((P){nx, ny, i});
      }
    }
  }

  int ans = INF;
  rep(i, 0, 3) ans = min(ans, d[gy][gx][i]);
  cout << ans << endl;
  // vector<vector<int>> d(h, vector<int>(w, INF));
  // d[sy][sx] = -1;
  // deque<P> q;
  // q.push_front((P){sx, sy, -1});
  // while(q.size()){
  //   P p = q.front(); q.pop_front();
  //   // cout << p.y << " " << p.x << endl;
  //   // if(p.y==gy && p.x==gx) break;

  //   for(int i = 0; i < 4; i++) {
  //     int ny = p.y + dy[i], nx = p.x + dx[i];
  //     if(ny<0 || nx<0 || ny>=h || nx>=w || a[ny][nx]=='#') continue;
  //     // if(p.dir != -1 && (p.dir+2)%4==i) continue;
  //     // cout << " " << ny << " " << nx << endl;
  //     if(p.dir != i && d[ny][nx] > d[p.y][p.x] + 1) {
  //       d[ny][nx] = d[p.y][p.x] + 1;
  //       q.push_back((P){nx, ny, i});
  //     }
  //     if(p.dir == i && d[ny][nx] > d[p.y][p.x]) {
  //       d[ny][nx] = d[p.y][p.x];
  //       q.push_front((P){nx, ny, i});
  //     }
  //   }
  // }
  // cout << d[gy][gx] << endl;
}