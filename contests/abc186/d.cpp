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
  ll n; cin >> n;
  vector<ll> a(n+1);
  a[0] = -1e10;
  rep(i, 1, n) cin >> a[i];

  sort(all(a));

  ll ans = 0;
  vector<ll> t(n+1);
  t[0] = 0;
  rep(i, 1, n) t[i] = t[i-1] + a[i];
  rep(i, 1, n) {
    ans += i*a[i];
    ans -= t[i];
  }
  // ans *= 2;
  cout << ans << endl;
}