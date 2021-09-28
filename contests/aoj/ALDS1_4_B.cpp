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
  vector<int> s(n);
  rep(i, 0, n-1) cin >> s[i];

  int q; cin >> q;
  vector<int> t(q);
  rep(i, 0, q-1) cin >> t[i];

  sort(all(s));

  int c = 0;
  for(auto v : t) {
    // cout << v << ": upper " << upper_bound(all(s), v) - s.begin() << " lower " << lower_bound(all(s), v) - s.begin() << endl;
    if(upper_bound(all(s), v) - lower_bound(all(s), v) > 0) c++;
  }

  cout << c << endl;
} 