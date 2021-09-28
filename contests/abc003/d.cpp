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

// O(N)
ll mod_factorial(ll n, ll p) {
  ll ans = 1;
  vector<ll> vec = modinvs(n, p);
  rep(i, 2, vec.size()-1) {
    ans = (ans * vec[i]) % p;
  }
  return (ans + p) % p;
}

// O(N)
ll mod_comb(ll n, ll k, ll p) {
  ll ans = 1;
  rep(i, 1, n) ans = (ans * i) % p;
  if(n>k && k>0) {
    ans = ans * mod_factorial(n-k, p) % p;
    ans = ans * mod_factorial(k, p) % p;
  }else if(n==k || k==0) {
    ans = 1;
  }else{
    ans = 0;
  }
  return (ans + p) % p;
}

int main() {
  int h, w, x, y, d, l;
  cin >> h >> w >> x >> y >> d >> l;

  // ll ans = mod_comb(x*y, d, MOD);

  // if(x*y > d + l) {
  //   if((x-1)*y >= d + l) ans = (ans - mod_comb((x-1)*y, d, MOD) * 2) % MOD;
  //   if(x*(y-1) >= d + l) ans = (ans - mod_comb(x*(y-1), d, MOD) * 2) % MOD;
  //   if((x-2)*y >= d + l) ans = (ans + mod_comb((x-2)*y, d, MOD)) % MOD;
  //   if(x*(y-2) >= d + l) ans = (ans + mod_comb(x*(y-2), d, MOD)) % MOD;
  //   if((x-1)*(y-1) >= d + l) ans = (ans + mod_comb((x-1)*(y-1), d, MOD) * 4) % MOD;
  //   if((x-2)*(y-1) >= d + l) ans = (ans - mod_comb((x-2)*(y-1), d, MOD) * 2) % MOD;
  //   if((x-1)*(y-2) >= d + l) ans = (ans - mod_comb((x-1)*(y-2), d, MOD) * 2) % MOD;
  //   if((x-2)*(y-2) >= d + l) ans = (ans + mod_comb((x-2)*(y-2), d, MOD)) % MOD;    
  // }

  ll ans = 0;
  rep(s, 0, 15) {
    int tx = x;
    int ty = y;
    if(s>>0 & 1) ty--;
    if(s>>1 & 1) ty--;
    if(s>>2 & 1) tx--;
    if(s>>3 & 1) tx--;
    if(tx<0 || ty<0) continue;
    if(__builtin_popcount(s) % 2 == 0) ans += mod_comb(tx*ty, d+l, MOD) * mod_comb(d+l, d, MOD) % MOD;
    else ans -= mod_comb(tx*ty, d+l, MOD) * mod_comb(d+l, d, MOD) % MOD;
    ans %= MOD;
  }

  ans %= MOD;
  ans = ans * (h-x+1) % MOD;
  ans = ans * (w-y+1) % MOD;
  cout << (ans + MOD) % MOD << endl;
  
}