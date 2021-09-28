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
const int INF = 1001001001;

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
int h, w;
vector<vector<int>> memo(100, vector<int>(100, 0));
vector<vector<bool>> flag(100, vector<bool>(100, false));
vector<string> a(100);

bool available(int y, int x) {
  if(y >= h || x >= w) return false;
  if(y < 0 || x < 0) return false;
  if(a[y][x] == '#') return false;
  return true;
}

int f(int y, int x) {
  if(flag[y][x]) return memo[y][x];

  int fans = -1;
  rep(i, 0, 2) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(!available(ny, nx)) continue;
    fans = -f(ny, nx);
    if(fans == 1) break;
  }

  flag[y][x] = true;
  return memo[y][x] = fans;
}

int main() {
  cin >> h >> w;
  rep(i, 0, h-1) cin >> a[i];

  flag[h-1][w-1] = true;
  memo[h-1][w-1] = -1;  
  int ans = f(0, 0);

  // // 終端を求める bfs
  // queue<pii> q;
  // vector<vector<bool>> used(h, vector<bool>(w, false));
  // q.push(pii(0,0));
  // vector<pii> ends;
  // while(q.size()) {
  //   pii p = q.front(); q.pop();
  //   int y = p.first, x = p.second;
  //   used[y][x] = true;
  //   bool stop = true;
  //   rep(i, 0, 2) {
  //     int nx = x + dx[i], ny = y + dy[i];
  //     if(!available(ny, nx)) continue;
  //     if(used[ny][nx]) continue;
  //     q.push(pii(ny, nx));
  //     stop = false;
  //   }
  //   if(stop) ends.push_back(pii(y, x));
  // }

  // // bfs from end to start
  // // for(auto e : ends) q.push(e);
  // vector<vector<int>> memo(h, vector<int>(w, -1));
  // for(auto e : ends) {
  //   // cout << e.first << "," << e.second << endl;
  //   q.push(e);
  //   while(q.size()) {
  //     pii p = q.front(); q.pop();
  //     int y = p.first, x = p.second;
  //     rep(i, 0, 2) {
  //       int py = y - dy[i], px = x - dx[i];
        
  //       if(!available(py, px)) continue;
  //       if(memo[y][x] == -1) memo[py][px] = 1;
  //       q.push(pii(py, px));
  //     }
  //   }
  // }

  if(memo[0][0] > 0) cout << "First" << endl;
  else cout << "Second" << endl;
}