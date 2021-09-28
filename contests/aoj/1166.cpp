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

int _main() {
  int w, h; cin >> w >> h;
  if(w==0 && h==0) return -1;

  vector< vector<int> > vw(32, vector<int>(32, 1)), hw(32, vector<int>(32, 1));
  // hw[0][0] = hw[h][w-1] = 0;
  rep(i, 0, 2*h-2) {
    if(i%2==0) rep(j, 0, w-2) cin >> vw[i/2][j+1];
    else rep(j, 0, w-1) cin >> hw[i/2+1][j];
  }

  // rep(y, 0, h-1) {
  //   rep(x, 0, w) {
  //     if(vw[y][x]) cout << "| ";
  //     else cout << "  ";
  //   }cout << endl;
  // }
  
  // rep(y, 0, h) {
  //   rep(x, 0, w-1) {
  //     if(hw[y][x]) cout << "_";
  //     else cout << " ";
  //   }cout << endl;
  // }

  // bfs
  vector< vector<int> > d(h, vector<int>(w, -1));
  d[0][0] = 1;
  
  queue<P> que;
  que.push(P(0, 0));
  while(que.size()) {
    P p = que.front(); que.pop();
    // cout << p.y << ", " << p.x << " " << h-1 << "," << w-1 << endl;

    // if(p.x == w-1 && p.y == h-1) cout << "aaa" << endl;
    if(p.x == w-1 && p.y == h-1) break;
    
    if(hw[p.y][p.x]==0 && d[p.y-1][p.x] == -1) {
      que.push(P(p.x, p.y-1));
      d[p.y-1][p.x] = d[p.y][p.x] + 1;
    }
    if(hw[p.y+1][p.x]==0 && d[p.y+1][p.x] == -1) {
      que.push(P(p.x, p.y+1));
      d[p.y+1][p.x] = d[p.y][p.x] + 1;
    }
    if(vw[p.y][p.x]==0 && d[p.y][p.x-1] == -1) {
      que.push(P(p.x-1, p.y));
      d[p.y][p.x-1] = d[p.y][p.x] + 1;
    }
    if(vw[p.y][p.x+1]==0 && d[p.y][p.x+1] == -1) {
      que.push(P(p.x+1, p.y));
      d[p.y][p.x+1] = d[p.y][p.x] + 1;
    }
  }

  if(d[h-1][w-1] == -1) cout << 0 << endl;
  else cout << d[h-1][w-1] << endl;
  
  return 0;
}

int main() {
  while(1) {
    int a = _main();
    if(a == -1) break;
  }
}