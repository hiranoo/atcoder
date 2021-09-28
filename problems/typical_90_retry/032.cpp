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
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  rep(i, 0, n-1) rep(j, 0, n-1) cin >> a[i][j];
  int m; cin >> m;
  vector<vector<bool>> bad(n, vector<bool>(n, false));
  rep(i, 0, m-1) {
    int x, y; cin >> x >> y; x--, y--;
    bad[x][y] = bad[y][x] = true;
  }

  vector<int> I(n);
  rep(i, 0, n-1) I[i] = i;

  ll ans = INF;
  do {
    ll res = 0;
    bool ok = true;
    rep(j, 0, n-1) res += a[I[j]][j];
    rep(i, 0, n-2) if(bad[I[i]][I[i+1]]) ok = false;
    if(ok) ans = min(ans, res);
  }while(next_permutation(I.begin(), I.end()));

  cout << (ans<INF? ans : -1) << endl;
}