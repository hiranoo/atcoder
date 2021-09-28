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

int dp[200005][200005];

int main() {
  int n; cin >> n;
  int n3 = 3*n;
  vector<int> A(n3);
  rep(i, 0, n3-1) cin >> A[i], --A[i];
  int m = n+1;
  rep(i, 0, m-1) rep(j, 0, m-1) dp[i][j] = -1e9;
  auto upd = [&](int i, int j, int x) {
    chmax(dp[i][j], x);
    chmax(dp[j][i], x);
    chmax(dp[i][n], x);
    chmax(dp[n][i], x);
    chmax(dp[n][j], x);
    chmax(dp[j][n], x);
    chmax(dp[n][n], x);
  };

  upd(A[0], A[1], 0);

  int base = 0;
  for(int ai = 2; ai < n3-1; ai += 3) {
    int x = A[ai], y = A[ai+1], z = A[ai+2];
    if(x==y && y==z) {
      base++;
      continue;
    }
    rep(_, 0, 2) {
      upd(x, y, max(dp[n][n], dp[z][z]+1));
      upd(x, y, dp[z][z]+1);

      upd()
      x, y, z = y, z, x;
    }
  }
}

int main() {
  int n; cin >> n;
  vector<int> a(3*n);
  rep(i, 0, 3*n-1) cin >> a[i], a[i]--;
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  dp[a[0]][a[1]] = 1;
  ll ma = 1;
  ll ma2 = 1;
  ll base = 0;
  rep(i, 1, n-1) {
    int p = a[3*i-1], q = a[3*i], r = a[3*i+1];
    if(p==q && q==r) {
      base++;
      continue;
    }

    rep(_, 0, 2) {
      p, q, r = q, r, p;

      if(p!=q && q==r) {
        rep(x, 0, n-1) {
          chmax(dp[p][x], dp[x][q]+1);
          chmax(ma2, dp[p][x]);
          dp[x][p] = dp[p][x];
        }
      }
      if(p!=q && q!=r) {
        chmax(dp[p][q], dp[r][r]);
        dp[q][p] = dp[p][q];

        rep(x, 0, n-1) {
          chmax(dp[p][x], ma2);
          chmax(ma2, dp[p][x]);
          dp[x][p] = dp[p][x];
        }
        
        chmax(ma, ma2);
        chmax(dp[p][q], ma);
        chmax(ma, dp[p][q]);
        dp[q][p] = dp[p][q];
      }
    }

    // cout << i << " " << ma << endl;
  }

  cout << ma + base << endl;
}