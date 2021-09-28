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
  int n, m; cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i, 0, n-1) cin >> a[i];
  rep(j, 0, m-1) cin >> b[j];

  sort(all(b));

  ll ans = INF;
  for(auto v : a) {
    int i = lower_bound(all(b), v) - b.begin();
    if(i < m) ans = min(ans, abs(b[i] - v));
    if(i > 0) ans = min(ans, abs(v - b[i-1]));
  }
  // cout << b.end() - b.begin() << endl;
  cout << ans << endl;
}