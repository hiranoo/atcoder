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
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;

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

int comb2(int n){
  return (n*(n-1))/2;
}

int comb3(int n){
  return (n*(n-1)*(n-2))/6;
}

int main(){
  int n; cin >> n;
  vector<int> prime_counter(n+1, 0);
  
  for(int i = 1; i <= n; i++){
    vector<pair<ll, ll>> v = factorize(i);
    for(auto p : v){
      prime_counter[p.first] += p.second;
    }
  }

  int ans = 0;
  
  rep(i, 2, n) if(74 <= prime_counter[i] ) ans++;

  rep(i, 2, n) rep(j, 2, n) if(i != j && 14 <= prime_counter[i] && 4 <= prime_counter[j]) ans++;
  
  rep(i, 2, n) rep(j, 2, n) if(i != j && 24 <= prime_counter[i] && 2 <= prime_counter[j]) ans++;
  
  rep(i, 2, n) rep(j, 2, n) rep(k, j+1, n) {
      if(i != j && i != k && 2 <= prime_counter[i] && 4 <= prime_counter[j] && 4 <= prime_counter[k]) ans++;
  }
  
  /*
  // 75
  rep(a, 2, n) if (74 <= prime_counter[a]) ans++;

  // 15*5
  rep(a, 2, n) rep(b, 2, n) if (a != b and 14 <= prime_counter[a] and 4 <= prime_counter[b]) ans++;

  // 3*25
  rep(a, 2, n) rep(b, 2, n) if (a != b and 24 <= prime_counter[a] and 2 <= prime_counter[b]) ans++;

  // 3*5*5
  rep(a, 2, n) rep(b, 2, n) rep(c, b + 1, n) {
      if (a != b and a != c and 2 <= prime_counter[a] and 4 <= prime_counter[b] and 4 <= prime_counter[c]) ans++;
  }   
  */
  cout << ans << endl;
}
