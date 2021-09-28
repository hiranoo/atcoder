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

int main() {
  int n, k; cin >> n >> k;
  vector<vector<ll>> a(n, vector<ll>(n));
  rep(i, 0, n-1) rep(j, 0, n-1) cin >> a[i][j];

  ll l = -1, r = 1e9+1;
  while(r - l > 1) {
    ll x = (l+r)/2;
    vector<vector<int>> b(n, vector<int>(n, 0));
    rep(i, 0, n-1) rep(j, 0, n-1) if(a[i][j] <= x) b[i][j] = 1;
    vector<vector<int>> sum(n+1, vector<int>(n+1, 0));
    rep(i, 1, n) rep(j, 1, n) {
      sum[i][j] = b[i-1][j-1];
      sum[i][j] += sum[i-1][j];
      sum[i][j] += sum[i][j-1];
      sum[i][j] -= sum[i-1][j-1];
    }
    // cout << 111 << endl;
    int th = k*k/2;
    if(k%2 == 1) th++;
    
    bool ok = false;
    rep(i, k, n) rep(j, k, n) {
      if(sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k] >= th) {
        ok = true;
        break;
      }
    }
    if(ok) r = x;
    else l = x;
    // cout << 222 << endl;
  }

  cout << r << endl;
}