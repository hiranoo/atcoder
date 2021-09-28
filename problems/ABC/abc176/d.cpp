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

int main() {
  int h, w; cin >> h >> w;
  int sx, sy, gx, gy; cin >> sy >> sx >> gy >> gx;
  --sx, --sy, --gx, --gy;
  vector<string> s(h);
  rep(i, 0, h-1) cin >> s[i];

  const int INF = 1001001001;
  vector<vector<int>> d(h, vector<int>(w, INF));
  d[sy][sx] = 0;
  deque<pii> q;
  q.push_front(pii(sy, sx));
  while(q.size()) {
    pii p = q.front(); q.pop_front();
    int y = p.first, x = p.second;
    // cout << y << " " << x << endl;
    if(y==gy && x==gx) break;

    for(int i = y-2; i <= y+2; i++) {
      for(int j = x-2; j <= x+2; j++) {
        if(i==y && j==x) continue;
        if(i<0 || j<0 || h<=i || w<=j || s[i][j]=='#') continue;
        if(abs(i-y)+abs(j-x) == 1) {
          if(d[i][j] > d[y][x]) {
            d[i][j] = d[y][x];
            q.push_front(pii(i, j));
          }
        }else{
          if(d[i][j] > d[y][x]+1) {
            d[i][j] = d[y][x]+1;
            q.push_back(pii(i, j));
          }
        }
      }
    }
  }
  if(d[gy][gx] < INF) cout << d[gy][gx] << endl;
  else cout << -1 << endl;
}