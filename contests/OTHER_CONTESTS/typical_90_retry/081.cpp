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
// const ll INF = 1e16;
const int INF = 1001001001;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}


int main() {
  int n, k; cin >> n >> k;
  
  vector<int> a(n), b(n);
  rep(i, 0, n-1) cin >> a[i] >> b[i];

  vector<vector<int>> cnt(5001, vector<int>(5001, 0)), sum(5001, vector<int>(5001, 0));
  rep(i, 0, n-1) cnt[b[i]][a[i]]++;

  rep(i, 1, 5000) rep(j, 1, 5000) sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + cnt[i][j];

  auto f= [&](vector<vector<int>> &c) {
    cout << "*********************" << endl;
    cout << "j "; rep(i, 1, 10) cout << i << " "; cout << endl;
    rep(i, 1, 10) {
      cout << i << " "; rep(j, 1, 10) cout << c[i][j] << " ";
      cout << endl;
    }
  };

  // f(cnt);
  // f(sum);

  int ans = 0;
  rep(i, 0, 5000) rep(j, 0, 5000) {
    int ni = min(5000, i+k+1), nj = min(5000, j+k+1);
    chmax(ans, sum[ni][nj] - sum[ni][j] - sum[i][nj] + sum[i][j]);
  }

  cout << ans << endl;
}