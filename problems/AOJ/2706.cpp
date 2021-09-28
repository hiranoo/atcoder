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

ll gcd(ll a, ll b){
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  ll p, q; cin >> p >> q;

  vector<pll> fact_q = factorize(q);
  vector<pll> fact_g = factorize(gcd(p, q));
  
  map<ll, ll> prime_count;
  for(auto p : fact_q){
    prime_count[p.first] = p.second;
  }

  for(auto p : fact_g){
    prime_count[p.first] -= p.second;
  }

  ll ans = 1;
  for(auto p : fact_q){
    if(prime_count[p.first] > 0) ans *= p.first;
  }
  
  cout << ans << endl;
}