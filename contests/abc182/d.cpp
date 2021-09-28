#include <bits/stdc++.h>
#include <atcoder/segtree>
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

  ll ans = 0;
  ll max_reach = 0;
  ll move = 0;
  ll pos = 0;
  for(auto v : a) {
    move += v;
    max_reach = max(max_reach, move);
    ans = max(ans, pos + max_reach);
    pos += move;
  }

  cout << ans << endl;
}