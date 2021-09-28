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

int dfs(int x, int y, vector<vector<int>> &a, vector<vector<int>> &used) {
  int fans = 0;
  int n= a.size(), m= a[0].size();

  used[y][x] = 1;
  rep(i, 0, 3) {
    int nx = x + dx[i], ny = y + dy[i];
    if( !(0<=nx && nx<m && 0<=ny && ny<n) ) continue;
    if(a[ny][nx]==0) continue;
    if(used[ny][nx]) continue;
    fans = max(fans, 1 + dfs(nx, ny, a, used));
  }
  used[y][x] = 0;
  return fans;
}

int main() {
  int m; cin >> m;
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(m, 0)), used(n, vector<int>(m, 0)); 
  rep(y, 0, n-1) rep(x, 0, m-1) cin >> a[y][x];

  int ans = 0;
  rep(y, 0, n-1) rep(x, 0, m-1) ans = max(ans, dfs(x, y, a, used));
  cout << ans << endl;
}