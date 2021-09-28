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
const int INF = 1001001001;

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];

  ll ans = 0;
  rep(j, 0, 59) {
    ll x = 0;
    rep(i, 0, n-1) if(a[i]>>j & 1) x++;
    ll now = x*(n-x) % MOD;
    now = now * ((1LL<<j)%MOD) % MOD;
    ans += now;
    ans %= MOD;
  }

  cout << (ans + MOD) % MOD << endl;
}