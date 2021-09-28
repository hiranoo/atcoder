#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
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

const ll MOD = 1e9 + 7;

/*****   素数を列挙して, vectorで返す関数 O(√n) **********************/

vector<ll> make_primes(ll n){
  vector<ll> primes;
  vector<ll> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for(ll i = 2; i <= n; i++){
    if(is_prime[i]){
      primes.emplace_back(i);
      for(ll j = 2*i; j <= n; j+=i){
        is_prime[j] = false;
      }
    }
  }

  return primes;  
}


/*****  素因数分解をして、vectorで返す関数 O(√n) *********************/

vector<pair<ll, ll>> factorize(ll n){
  vector<pair<ll, ll>> v;
  for(ll i = 2; i*i <= n; i++){
    if(n % i != 0) continue;
    ll idx = 0;
    while(n % i == 0){
      idx++;
      n /= i;
    }
    v.push_back(make_pair(i, idx));
  }
  if(n != 1) v.push_back(make_pair(n, 1));
  return v;
}

/***** 素数列を使って高速に素因数分解する関数 ***************************/
vector<pll> fast_factorize(ll n, vector<ll> primes){
  vector<pll> v;
  for(auto p : primes){
    if(p > n) break;
    if(n % p != 0) continue;
    ll idx = 0;
    while(n % p == 0){
      idx++;
      n /= p;
    }
    v.emplace_back(pll(p, idx));
  }
  if(n != 1) v.emplace_back(pll(n, 1));
  return v;
}

ll modinv(ll a, ll m){
  ll b = m, u = 1, v = 0;
  while(b){
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if(u < 0) u += m;
  return u;
}

ll gcd(ll a, ll b){
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a / gcd(a, b) * b;
}


/**
 * 悪い例
 * mod計算で約数の情報が消えるため、正しい値にならない

ll lcm_mod(ll a, ll b, ll m){
  return (a%m * b%m * modinv(gcd(a, b), m)) % m;
}

*/

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  vector<ll> primes = make_primes(1000);
  map<ll, ll> fact;
  for(auto val : a){
    for(auto p : fast_factorize(val, primes)){
      fact[p.first] = max(fact[p.first], p.second);
    }
  } 

  ll L = 1;
  for(auto iter = fact.begin(); iter != fact.end(); iter++){
    //cout << iter->first << " ** " << iter->second << endl;
    L *= pow(iter->first, iter->second);
    L %= MOD;
  }


  ll ans = 0;
  for(auto v : a) {
    ans += modinv(v, MOD);
    ans %= MOD;
  }

  ans *= L;
  ans %= MOD;

  cout << ans << endl;
}
