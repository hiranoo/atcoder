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

int n, x, y;
vector<vector<int>> memo(2, vector<int>(2005));
vector<vector<bool>> flag(2, vector<bool>(2005, false));
vector<int> a(2005);

int f(int id, int turn, int x, int y) {
  if(id == n) return abs(x-y);
  if(flag[turn][id]) return memo[turn][id];

  int ma = -INF, mi = INF;
  if(turn) {
    rep(i, id, n-1) ma = max(ma, f(i+1, 0, a[i], y));
    flag[1][id] = true;
    return memo[1][id] = ma;
  }else{
    rep(i, id, n-1) mi = min(mi, f(i+1, 1, x, a[i]));
    flag[0][id] = true;
    return memo[0][id] = mi;
  }
}

int main() {
  cin >> n >> x >> y;
  rep(i, 0, n-1) cin >> a[i];

  int ans = f(0, 1, x, y);
  cout << ans << endl;
}