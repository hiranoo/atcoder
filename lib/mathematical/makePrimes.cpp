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
const ll MOD = 1e9+7;


/*****   素数を列挙して, vectorで返す関数 O(√n) **********************/

vector<int> make_primes(int n){
  vector<int> primes;
  vector<int> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; i <= n; i++){
    if(is_prime[i]){
      primes.emplace_back(i);
      for(int j = 2*i; j <= n; j+=i){
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

/***** make_primes()で生成した素数列を使って高速に素因数分解する関数 ***************************/
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

/**** mod mで aの逆元を計算する *********/
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

/*** 最大公約数 **************************/
ll gcd(ll a, ll b){
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

/*** 最小公倍数 **************************/
ll lcm(ll a, ll b){
  return a / gcd(a, b) * b;
}


/**
 * 悪い例
 * mod計算で約数の情報が消えるため、正しい値にならない
 * LCMが欲しいときは素直に素因数分解をするといい
 */
ll lcm_mod(ll a, ll b, ll m){
  return (a%m * b%m * modinv(gcd(a, b), m)) % m;
}


int main(){
  int n; cin >> n;
  clock_t start, end;

  vector<double> times;

  rep(i, 0, 9){
    start = clock();
    vector<int> primes = makePrimes(n);
    end = clock();

    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    times.emplace_back(time);
  }


  /*
  for(auto p : primes) cout << p << " ";
  cout << endl;
  */

  //cout << primes.size() << endl;

  

  for(auto t : times) printf("time %lf ms\n", t);
}