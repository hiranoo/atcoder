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
  vector<int> d(n);
  rep(i, 0, n-1) cin >> d[i];
  sort(all(d));

  if(n %2 == 1) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  rep(i, 2, 100000) {
    if(lower_bound(all(d), i) - d.begin() == n/2) ans++;
  }
  cout << ans << endl;
}