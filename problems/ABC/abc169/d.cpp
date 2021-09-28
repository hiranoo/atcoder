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

ll count_div(ll q){
  //cout << "q:" << q << endl;
  ll l = -1, r = q+1;
  while(r - l > 1){
    ll k = (l+r)/2;
    if(q * 2 >= k * (k+1) ) l = k;
    else r = k;
  }
  //cout << l << endl;
  return l;
}

int main(){
  ll n; cin >> n;

  vector<pair<ll, ll>> v = factorize(n);
  int ans = 0;
  for(auto p : v){
    //cout << p.first << " ** " << p.second << endl;
    ans += count_div(p.second);
  }
  cout << ans << endl;
}