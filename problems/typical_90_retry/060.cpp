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
// const ll INF = 1e16;
const int INF = 1001001001;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

vector<int> f(vector<int> &a) {
  int n = a.size();
  vector<int> dp(n, INF); // dp[i]:= 長さi+1の増加部分列のとりうる末尾の最小値
  vector<int> b(n); // a[i]を末尾とする増加部分列の最大長をメモする

  rep(i, 0, n-1) {
    int j = lower_bound(all(dp), a[i]) - dp.begin();
    b[i] = j+1;
    dp[j] = a[i];
  }
  return b;
}

int main() {
  int n; cin >> n;
  vector<int> a1(n), a2(n);
  rep(i, 0, n-1) cin >> a1[i];

  a2 = a1;
  reverse(all(a2));

  vector<int> b1 = f(a1);
  vector<int> b2 = f(a2);

  // rep(i, 0, n-1) cout << i << " "; cout << endl;
  // rep(i, 0, n-1) cout << b1[i] << " "; cout << endl;
  // rep(i, 0, n-1) cout << b2[n-1-i] << " "; cout << endl;
  // cout << endl;

  int ans = 0;
  rep(i, 0, n-1) chmax(ans, b1[i]+b2[n-1-i]-1);

  cout << ans << endl;
}