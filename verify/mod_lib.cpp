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

ll modpow(ll a, ll p, ll m) {
  ll ans = 1;
  while(p) {
    if(p & 1) ans = ans * a % m;
    a = a * a % m;
    p >>= 1;
  }
  return ans;
}

ll modinv(ll a, ll m) {
  return modpow(a, m-1, m);
}

vector<ll> modinvs(ll n, ll p) {
  vector<ll> ans(n+1);
  ans[0] = 0;
  ans[1] = 1;
  rep(i, 2, n) ans[i] = (-p/i * ans[p%i]) % p;
  rep(i, 0, n) ans[i] = (ans[i] + p) % p;
  return ans;
}

ll mod_factorial(ll n, ll p) {
  ll ans = 1;
  vector<ll> v = modinvs(n, p);
  rep(i, 1, n) {
    ans = (ans * v[i]) % p;
  }
  return (ans + p) % p;
}

ll mod_comb(ll n, ll k, ll p) {
  ll ans = 1;
  rep(i, 1, n) ans = (ans * i) % p;
  ans = (ans * mod_factorial(n-k, p) * mod_factorial(k, p)) % p;
  return ans;
}

int main() {
  ll n, k; cin >> n >> k;
  ll p = 31;
  ll i = 0;
  for(auto v : modinvs(n, p)) {
    cout << i << ":" << v << endl;
    i++;
  }
  cout << mod_comb(n, k, p) << endl;
}