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
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e16;

int main() {
  int n; cin >> n;
  vector<vector<int>> a(1005, vector<int>(1005, 0));
  rep(i, 0, n-1) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    a[y1][x1]++;
    a[y1][x2]--;
    a[y2][x1]--;
    a[y2][x2]++;
  }

  rep(y, 0, 1001) rep(x, 0, 1001) a[y][x+1] += a[y][x];
  rep(x, 0, 1001) rep(y, 0, 1001) a[y+1][x] += a[y][x];

  vector<int> ans(n+1, 0);
  rep(y, 0, 1000) rep(x, 0, 1000) ans[a[y][x]]++;

  rep(i, 1, n) cout << ans[i] << endl;
}