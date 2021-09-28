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
const ll MOD = 998244353;
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

// O(log m)
ll modpow(ll a, ll p, ll m) {
  ll ans = 1;
  while(p) {
    if(p & 1) ans = ans * a % m;
    a = a * a % m;
    p >>= 1;
  }
  return ans;
}

// O(log m)
ll modinv(ll a, ll m) {
  return modpow(a, m-2, m);
}

// O(N)
vector<ll> modinvs(ll n, ll p) {
  vector<ll> ans(n+1);
  ans[0] = 0;
  ans[1] = 1;
  rep(i, 2, n) ans[i] = (-p/i * ans[p%i] + p) % p;
  return ans;
}

int main() {
  int n, m, k; cin >> n >> m >> k;

  vector<ll> cumInvs(n); cumInvs[0] = 1;
  vector<ll> invs = modinvs(n-1, MOD);
  rep(i, 1, n-1) cumInvs[i] = cumInvs[i-1] * invs[i] % MOD;
  ll tot = 1;
  rep(i, 1, n-1) tot = tot * i % MOD;

  vector<ll> a(n);
  a[0] = 1;
  rep(i, 1, n-1) a[i] = a[i-1] * (m-1) % MOD;
  
  ll ans = 0;
  rep(i, 0, k) {
    ll ret = tot;
    ret = ret * cumInvs[i] % MOD;
    ret = ret * cumInvs[n-1-i] % MOD;
    ret = (ret * m % MOD) * a[n-1-i] % MOD;
    ans += ret;
    ans %= MOD;
  }

  cout << (ans + MOD) % MOD << endl;
}