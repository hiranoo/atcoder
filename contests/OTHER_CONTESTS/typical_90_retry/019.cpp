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
const ll INF = 1e10;
const int MAX_N = 10000;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

vector<vector<ll>> dp(MAX_N, vector<ll>(MAX_N));
vector<vector<bool>> flag(MAX_N, vector<bool>(MAX_N, false));
vector<ll> a;

ll f(int l, int r) {
  if(flag[l][r]) return dp[l][r];
  // if(l%2 == r%2) return INF;
  if(r-l == 1) return abs(a[l] - a[r]);

  ll fans = abs(a[l] - a[r]) + f(l+1, r-1);
  for(int k = l+1; k <= r-2; k += 2) chmin(fans, f(l, k) + f(k+1, r));
  // if(fans > INF) fans = INF;

  flag[l][r] = true;
  return dp[l][r] = fans;
}

int main() {
  int n; cin >> n; n *= 2;
  a.resize(n);
  rep(i, 0, n-1) cin >> a[i];

  cout << f(0, n-1) << endl;
}