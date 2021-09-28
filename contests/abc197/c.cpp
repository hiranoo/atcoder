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
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  int ans = INT_MAX;
  rep(s, 1, (1 << n)-1) {
    int res = 0;
    int sub = 0;
    rep(i, 0, n-1) {
      sub |= a[i];
      if(s & 1<<i) {
        res ^= sub;
        sub = 0;
      }
    }
    if(s & (1<<(n-1))) ans = min(ans, res);
  }

  cout << ans << endl;
}