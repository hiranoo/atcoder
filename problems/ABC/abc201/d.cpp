#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template<class T> inline bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;
const ll INF = 1e18;


int h, w;

vector<vector<ll>> dp(2000, vector<ll>(2000, 0));
vector<vector<bool>> flag(2000, vector<bool>(2000, false));

int f(int y, int x, vector<vector<int>> &a) {
  if(flag[y][x]) return dp[y][x];

  int res = -1001001001;
  if(x+1 < w) res = max(res, a[y][x+1] - f(y, x+1, a));
  if(y+1 < h) res = max(res, a[y+1][x] - f(y+1, x, a));

  // if(x+1 < w) cout << res << " " << a[y][x+1] - f(y, x+1, a) << endl;
  // if(y+1 < h) cout << res << " " << a[y+1][x] - f(y+1, x, a) << endl;

  flag[y][x] = true;
  return dp[y][x] = res;
}

int main() {
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(y, 0, h-1) {
    string s; cin >> s;
    rep(x, 0, w-1) {
      if(s[x] == '+') a[y][x] = 1;
      else a[y][x] = -1;
    }
  }

  flag[h-1][w-1] = true;
  
  f(0, 0, a);
  if(dp[0][0] > 0) cout << "Takahashi" << endl;
  else if(dp[0][0] < 0) cout << "Aoki" << endl;
  else cout << "Draw" << endl;
}