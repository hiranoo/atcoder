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


ll gcd(ll a, ll b){
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  ll a, b; cin >> a >> b;

  if(a == 1 || b == 1) {
    cout << 1 << endl;
    return 0;
  }

  ll g = gcd(a, b);
  int primes = 0;
  for(int i = 2; i*i <= g; i++){
    if(is_prime[i]) primes++;
  }
  ll num = g;

  int ans = 1 + num;
  
  cout << ans << endl;
  return 0;
}