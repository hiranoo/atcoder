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
const int INF = 1001001001;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

int dfs1(int i, int j, int si, int sj, vector<string> &c, vector<vector<bool>> &used) {
  if(i==si && j==sj && used[i][j]) return 0;

  int h = c.size(), w = c[0].size();
  int res = -100000;
  used[i][j] = true;
  rep(k, 0, 3) {
    int ni = i + di[k], nj = j + dj[k];
    
    if(ni<0 || nj<0 || h<=ni || w<=nj || c[ni][nj]=='#') continue;
    if(!(si==ni && sj==nj) && used[ni][nj]) continue;
    res = max(res, dfs1(ni, nj, si, sj, c, used)+1);
  }
  used[i][j] = false;

  return res;
}

// int dx[4] = { 0, 1, 0, -1 };
// int dy[4] = { 1, 0, -1, 0 };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs2(int sx, int sy, int px, int py, vector<string> &c, vector<vector<bool>> &used) {
	if (sx == px && sy == py && used[px][py] == true) return 0;
	used[px][py] = true;
  int H = c.size(), W = c[0].size();
	int ret = -10000;
	for (int i = 0; i < 4; i++) {
		int nx = px + dx[i], ny = py + dy[i];
		if (nx < 0 || ny < 0 || nx >= H || ny >= W || c[nx][ny] == '#') continue;
		if ((sx != nx || sy != ny) && used[nx][ny] == true) continue;
		int v = dfs2(sx, sy, nx, ny, c, used);
		ret = max(ret, v + 1);
	}
	used[px][py] = false;
	return ret;
}


int main() {
  int h, w; cin >> h >> w;
  vector<string> c(h);
  rep(i, 0, h-1) cin >> c[i];

  int ans1 = -1, ans2 = -1;
  vector<vector<bool>> used(h, vector<bool>(w, false));
  rep(i, 0, h-1) rep(j, 0, w-1) {
    chmax(ans1, dfs1(i, j, i, j, c, used));
    chmax(ans2, dfs2(i, j, i, j, c, used));
  }

  cout << ans1 << " " << ans2 << endl;

  // if(ans <= 2) ans = -1;
  // cout << ans << endl;
}
