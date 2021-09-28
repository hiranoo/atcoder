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

int h, w;

struct P {
  int cost, x, y;
  P() {}
  P(int cost, int x, int y) : cost(cost), x(x), y(y) {}
  void show() {
    cout << "cost: " << cost << " x: " << x << " y: " << y << endl;
  }
};

bool inside(int x, int y) {
  if(0<=x && x<w && 0<=y && y<h) return true;
  return false;
}

int main() {
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h-1) cin >> s[i];

  const int INF = 1001001001;
  deque<P> que;
  que.push_front(P(0, 0, 0));
  map<pii, int> move;
  move[pii(-1, 0)]=move[pii(1, 0)]=move[pii(0, 1)]=move[pii(0, -1)]=1;

  vector<vector<int>> d(h, vector<int>(w, INF));

  while(que.size()) {
    P p = que.front(); que.pop_front();
    // p.show();
    // if(p.x == w-1 && p.y == h-1) {
    //   break;
    // }
    rep(dy, -2, 2) rep(dx, -2, 2) {
      int nx = p.x + dx;
      int ny = p.y + dy;
      if(!inside(nx, ny)) continue;
      if(abs(dy)==2 && abs(dx)==2) continue;
      if(dy==0 && dx==0) continue;
      if(move[pii(dx, dy)]==1 && s[ny][nx]=='.') {
        if(d[ny][nx] > p.cost) {
          que.push_front(P(p.cost, nx, ny));
          d[ny][nx] = p.cost;
        }
      }
      else if(d[ny][nx] > p.cost + 1) {
        que.push_back(P(p.cost+1, nx, ny));
        d[ny][nx] = p.cost + 1;
      }
    }
  }

  cout << d[h-1][w-1] << endl;
  
}