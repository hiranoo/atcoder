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

ll modpow(ll a, ll p) {
  ll ans = 1;
  while(p > 0) {
    if(p & 1) ans = ans * a % MOD;
    a = a * a % MOD;
    p >>= 1;
  }
  return ans;
}

int main() {
  ll n; cin >> n;

  if(n == 1) {
    cout << 0 << endl;
    return 0;
  }
  // ll ans = n * (n-1) % MOD;
  // ans = ans * modpow(10LL, n-2) % MOD;

  ll ans = modpow(10, n) - 2 * modpow(9, n) + modpow(8, n);
  ans %= MOD;
  cout << (ans + MOD) % MOD << endl;
}