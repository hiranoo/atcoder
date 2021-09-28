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
// const ll MOD = 1e9+7;
const ll INF = 1e18;

int main() {
  int n, m; cin >> n >> m;
  vector<int> s(n-1), a(m);
  rep(i, 0, n-2) cin >> s[i];
  rep(i, 0, m-1) cin >> a[i];
  vector<int> dsum(n, 0);
  rep(i, 1, n-1) {
    dsum[i] = dsum[i-1] + s[i-1];
  }

  // for(auto d : dsum) cout << d << " "; cout << endl;
  int i = 0;
  ll ans = 0;
  const ll MOD = 1e5;
  for(auto v : a) {
    ans += abs(dsum[i+v] - dsum[i]);
    ans %= MOD;
    i += v;
  }
  cout << (ans + MOD) % MOD << endl;
}