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
const ll MOD = 998244353;
const ll INF = 1e15;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

vector<vector<ll>> dp(205, vector<ll>(205, -INF));
vector<vector<bool>> flag(205, vector<bool>(205, false));

ll f(int l, int r, set<pii> &s) {
  // printf("l: %d, r: %d\n", l, r);
  if(flag[l][r]) return dp[l][r];
  if(l%2 == r%2) return -INF;
  if(r-l == 1) {
    flag[l][r] = true;
    if(s.count(pii(l, r)) > 0) {
      return dp[l][r] = 1;
    }else{
      return dp[l][r];
    }
  }

  ll fans = 0;
  if(s.count(pii(l, r)) > 0 && f(l+1, r-1, s) > 0) fans = ( (f(l+1, r-1, s) % MOD) + MOD ) % MOD;
  for(int k = l+1; k <= r-2; k++) {
    if(f(l, k, s) < 0 || f(k+1, r, s) < 0) continue;
    ll tmp = 2 * f(l, k, s) * f(k+1, r, s);
    if(tmp > 0) fans = (((fans + tmp) % MOD) + MOD) % MOD;
  }

  flag[l][r] = true;
  if(fans > 0) dp[l][r] = fans;
  return dp[l][r];
}

int main() {
  int n, m; cin >> n >> m; n*=2;
  set<pii> s;
  rep(i, 0, m-1) {
    int a, b; cin >> a >> b; a--, b--;
    s.insert(pii(a, b));
  }

  // for(auto v : s) cout << v.first << "," << v.second << " "; cout << endl;

  ll ans = f(0, n-1, s);
  if(ans > 0) cout << ans << endl;
  else cout << 0 << endl;

  // cout << "i "; rep(j, 0, n-1) cout << j+1 << " "; cout << endl;
  // rep(i, 0, n-1) {
  //   cout << i+1 << " "; rep(j, 0, n-1) cout << (dp[i][j]>=0? dp[i][j]: 0) << " "; cout << endl;
  // }
}