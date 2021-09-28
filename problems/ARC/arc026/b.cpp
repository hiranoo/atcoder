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


vector<pll> factorize(ll n){
  vector<pll> v;
  for(ll i = 2; i*i <= n; i++){
    if(n % i != 0) continue;
    ll idx = 0;
    while(n % i == 0){
      idx++;
      n /= i;
    }
    v.emplace_back(pll(i, idx));
  }
  if(n != 1) v.emplace_back(pll(n, 1));
  return v;
}



int main(){
  ll n; cin >> n;

  ll mul = 1;
  for(auto p : factorize(n)){
    //cout << p.first << " ** " << p.second << endl;
    ll ret = 1;
    for(ll i = 1; i <= p.second; i++){
      ret += pow(p.first, i);
    }
    //cout << ret << endl;
    mul *= ret;
  }
  mul -= n;
  //cout << mul << endl;

  if(mul == n) cout << "Perfect" << endl;
  if(mul < n) cout << "Deficient" << endl;
  if(mul > n) cout << "Abundant" << endl;  
}