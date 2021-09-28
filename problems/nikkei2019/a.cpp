#include <bits/stdc++.h>
// #include <atcoder/segtree>
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

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];
  vector<ll> sum(n+1, 0);
  rep(i, 1, n) {
    sum[i] = sum[i-1] + a[i-1];
  }

  rep(k, 1, n) {
    ll ans = 0;
    rep(i, 0, n-k) ans = max(ans, sum[i+k] - sum[i]);
    cout << ans << endl;
  }
}