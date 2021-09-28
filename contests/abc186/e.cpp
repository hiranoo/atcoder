#include <bits/stdc++.h>
#include <atcoder/all>
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
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

// a**p % m
// O(log m)
ll modpow(ll a, ll p, ll m) {
  ll ans = 1;
  while(p > 0) {
    if(p & 1) ans = ans * a % m;
    a = a * a % m;
    p >>= 1;
  }
  return ans;
}

ll euler_modinv(ll a, ll m) {
  ll _m = m;
  vector<ll> ps;
  for(ll i = 2; i * i <= m; i++) {
    int idx = 0;
    while(m % i == 0) {
      idx++;
      m /= i;
    }
    if(idx>0) ps.push_back(i);
  }if(m != 1) ps.push_back(m);

  ll phi = _m;
  for(ll p : ps) phi = phi * (p-1) / p;

  return modpow(a, phi-1, _m);
}

int main() {
  int T; cin >> T;
  vector<ll> ans;
  while(T--) {
    ll n, s, k; cin >> n >> s >> k;
    ll g = __gcd(k, n);
    if(s%g != 0) {
      ans.push_back(-1);
      continue;
    }
    n /= g, k /= g, s /= g;
    ll a = (n-s)*euler_modinv(k, n) % n;
    a = (a + n) % n;
    ans.push_back(a);
  }

  for(auto v : ans) cout << v << endl;
}