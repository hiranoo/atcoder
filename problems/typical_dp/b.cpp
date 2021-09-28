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

vector<vector<int>> dp(1005, vector<int>(1005));
vector<vector<bool>> flag(1005, vector<bool>(1005, false));
vector<int> a(1005), b(1005);

int f(int i, int j) {
  if(flag[i][j]) return dp[i][j];
  int ret = -INF;
  if(i) ret = max(ret, a[i] - f(i-1, j));
  if(j) ret = max(ret, b[j] - f(i, j-1));
  flag[i][j] = true;
  return dp[i][j] = ret;
}

int main() {
  int n, m; cin >> n >> m;
  for(int i = n; i >= 1; i--) cin >> a[i];
  for(int j = m; j >= 1; j--) cin >> b[j];
  

  dp[0][0] = 0;
  flag[0][0] = true;

  f(n, m);
  // cout << "done" << endl;
  // cout << dp[n][m] << endl;
  // cout << "*************" << endl;
  // cout << "  ";
  // rep(j, 0, m) cout << j << " "; cout << endl;
  // rep(i, 0, n) {
  //   cout << i << " ";
  //   rep(j, 0, m) {
  //     cout << dp[i][j] << " ";
  //   }cout << endl;
  // }

  // int ans = 0;
  // int i = n, j = m;
  // while(i+j > 0) {
  //   // cout << i << " " << j << endl;
  //   if(i==0) {
  //     if(j%2 == (n+m)%2) ans += b[j];
  //     j--;
  //   }
  //   else if(j==0) {
  //     if(i%2 == (n+m)%2) ans += a[i];
  //     i--;
  //   }
  //   else {
  //     bool take_a = true;
  //     if(dp[i-1][j] > dp[i][j-1]) take_a = false;
  //     if((i+j) % 2 == (n+m) % 2) {
  //       if(take_a) ans += a[i];
  //       else ans += b[j];
  //     }
  //     if(take_a) i--;
  //     else j--;
  //   }
  // }

  int ans = 0;
  rep(i, 1, n) ans += a[i];
  rep(i, 1, m) ans += b[i];
  ans += dp[n][m];
  ans /= 2;
  cout << ans << endl;
} 