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
const ll INF = 1e18;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

struct Mat {
  int n;
  vector<vector<ll>> m;
  Mat() {}
  Mat(int _n) {
    n = _n;
    m = vector<vector<ll>>(n, vector<ll>(n, 0));
  }

  inline const vector<ll> &operator[](int k) const {
    return (m.at(k));
  }

  inline vector<ll> &operator[](int k) {
    return (m.at(k));
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
    rep(i, 0, n-1) rep(j, 0, n-1) rep(k, 0, n-1) B.m[i][j] += m[i][k] * M.m[k][j];
    return B;
  }
};

int main() {
  int n; cin >> n;
  vector<ll> x(n), y(n);
  rep(i, 0, n-1) cin >> x[i] >> y[i];

  int m; cin >> m;
  vector<Mat> Ms(m+1, Mat(3));
  rep(i, 0, 2) Ms[0][i][i] = 1;
  rep(i, 1, m) {
    Mat A(3); A[2][2] = 1;
    int a; cin >> a; ll p;
    switch (a) {
      case 1:
        A[0][1] = 1, A[1][0] = -1;
        break;
      case 2:
        A[0][1] = -1, A[1][0] = 1;
        break;
      case 3:
        cin >> p;
        A[0][0] = -1, A[0][2] = 2*p, A[1][1] = 1;
        break;
      case 4:
        cin >> p;
        A[0][0] = 1, A[1][2] = 2*p, A[1][1] = -1;
        break;
    }
    Ms[i] = A * Ms[i-1];
  }

  int q; cin >> q;
  while(q--) {
    int a, b; cin >> a >> b; b--;
    ll X = Ms[a][0][0] * x[b] + Ms[a][0][1] * y[b] + Ms[a][0][2] * 1;
    ll Y = Ms[a][1][0] * x[b] + Ms[a][1][1] * y[b] + Ms[a][1][2] * 1;
    cout << X << " " << Y << endl;
  }
}