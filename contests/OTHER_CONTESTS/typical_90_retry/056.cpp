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
const ll INF = 1e16;

bool chmax(ll &a, ll b) {if(a < b) {a = b; return true;} return false;}
bool chmin(ll &a, ll b) {if(a > b) {a = b; return true;} return false;}

bool restore(int i, int j, vector<int> &a, vector<int> &b, vector<vector<bool>> &memo, string &ans) {
  // cout << i << ", " << j << endl;
  if(i == 0 && j == 0) return true;
  bool res = false;
  if(j>=a[i] && memo[i-1][j-a[i]] && restore(i-1, j-a[i], a, b, memo, ans)) {
    ans += "A"; return true;
  }
  if(j>=b[i] && memo[i-1][j-b[i]] && restore(i-1, j-b[i], a, b, memo, ans)) {
    ans += "B"; return true;
  }
  return false;
}

int main() {
  int n, s; cin >> n >> s;
  vector<int> a(n+1), b(n+1);
  rep(i, 1, n) cin >> a[i] >> b[i];

  vector<vector<bool>> dp(101, vector<bool>(100005, false));
  vector<vector<bool>> memo = dp;

  dp[0][0] = memo[0][0] = true;
  rep(i, 1, n) rep(j, 0, 100001) {
    if(!dp[i-1][j]) continue;
    if(j+a[i] <= s) dp[i][j+a[i]] = memo[i][j+a[i]] = true;
    if(j+b[i] <= s) dp[i][j+b[i]] = memo[i][j+b[i]] = true;
    dp[i-1][j] = false;
  }

  if(!dp[n][s]) {
    cout << "Impossible" << endl;
    return 0;
  }

  // for(int i = n; i >= 0; i--) for(int j = s; j >= 0; j--) if(memo[i][j]) cout << i << ", " << j << endl;

  int i = n, j = s;
  string ans = "";
  while(i > 0) {
    if(j>=a[i] && memo[i-1][j - a[i]]) {
      j -= a[i--]; 
      ans += "A";
    }
    else if(j>=b[i] && memo[i-1][j - b[i]]) {
      j -= b[i--]; 
      ans += "B";
    }
  }
  reverse(all(ans));

  // string ans = "";
  // restore(n, s, a, b, memo, ans);

  cout << ans << endl;
}