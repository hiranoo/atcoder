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


int main(){
  ll n; cin >> n;

  vector<pll> fact = factorize(n);
  
  ll min_ans, max_ans;

  if(fact.size() == 1 && fact[0].second == 1) min_ans = 1;
  else min_ans = 2;

  
}