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
const int MAX_N = 10000;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

vector<vector<ll>> dp(MAX_N, vector<ll>(MAX_N));
vector<vector<bool>> flag(MAX_N, vector<bool>(MAX_N, false));

ll f(int i, int k) {
  if(flag[i][k]) return dp[i][k];
  if(i <= k) return dp[i][k] = i+1;

  flag[i][k] = true;
  return dp[i][k] = f(i-k, k) + f(i-1, k);
}

struct Mat {
  int n;
  vector<vector<ll>> m;
  Mat() {}
  Mat(int _n) {
    n = _n;
    m = vector<vector<ll>>(n, vector<ll>(n, 0));
  }

  void set(int i, int j, ll v) {
    m[i][j] = v;
  }

  ll get(int i, int j) {
    return m[i][j];
  }

  int size() {
    return n;
  }

  void show() {
    cout << endl;
    rep(i, 0, n-1) {
      rep(j, 0, n-1) cout << m[i][j] << " ";
      cout << endl;
    }cout << endl;
  }

  Mat operator*(const Mat &M) {
    Mat B(n);
    rep(i, 0, n-1) rep(j, 0, n-1) rep(k, 0, n-1) B.m[i][j] += m[i][k] * M.m[k][j] % MOD, B.m[i][j] %= MOD;
    return B;
  }
};

Mat matpow(Mat A, int n) {
  int s = A.size();
  Mat B(s);
  rep(i, 0, s-1) B.set(i, i, 1);
  while(n > 0) {
    if(n & 1) B = B * A;
    A = A * A;
    n >>= 1;
  }
  return B;
}

ll modpow(ll a, int n) {
  ll ans = 1;
  while(n > 0) {
    if(n & 1) ans = ans * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return ans;
}

int main() {
  int n; cin >> n;

  // k == 1
  cout << (modpow(2, n) - 1) % MOD << endl;
  // k >= 2
  rep(k, 2, n) {
    Mat A(k);
    A.set(0, 0, 1);
    A.set(0, k-1, 1);
    rep(i, 1, k-1) A.set(i, i-1, 1);
    A = matpow(A, n-k);
    // cout << n-k << "乗:" << endl;
    // A.show();
    ll ans = 0;
    rep(i, 0, k-1) ans += A.get(0, i) * (k-i+1) % MOD, ans %= MOD;
    cout << ((ans - 1)%MOD + MOD) % MOD << endl;
  }

  // cout << "debug" << endl;
  // cout << modpow(2, 32) << endl;

  // int k = 2;
  // Mat A(k);
  // A.set(0, 0, 1);
  // A.set(0, k-1, 1);
  // rep(i, 1, k-1) A.set(i, i-1, 1);
  // A.show();
  // rep(i, 2, 5) matpow(A, i).show();
  // rep(i, 1, n) cout << f(n, i) - 1 << endl;
}