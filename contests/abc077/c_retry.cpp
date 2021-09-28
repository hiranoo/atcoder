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
  vector<int> a(n), b(n), c(n);
  rep(i, 0, n-1) cin >> a[i];
  rep(i, 0, n-1) cin >> b[i];
  rep(i, 0, n-1) cin >> c[i];

  sort(all(a));
  sort(all(b));
  sort(all(c));

  ll ans = 0;
  int pre = 0;
  for(auto v : b) {
    if(pre == v) continue;

    int an = lower_bound(all(a), v) - a.begin();
    int cn = n - (int)(upper_bound(all(c), v) - c.begin());

    ans += an * cn;
    pre = v;
  }
  cout << ans << endl;
}