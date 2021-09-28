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
  int D; cin >> D;
  int n; cin >> n;
  int m; cin >> m;
  vector<int> s(n+1);
  s[0] = 0; s[n] = D;
  rep(i, 1, n-1) cin >> s[i];
  vector<int> house(m);
  rep(i, 0, m-1) cin >> house[i];

  sort(all(s));
  sort(all(house));

  // for(auto ss : s) cout << ss << " "; cout << endl;
  // for(auto h : house) cout << h << " "; cout << endl;

  ll ans = 0;
  for(auto h : house) {
    if(h == 0) continue;
    int i = lower_bound(all(s), h) - s.begin();
    ans += min(s[i]-h, h-s[i-1]);
  }
  cout << ans << endl;
}