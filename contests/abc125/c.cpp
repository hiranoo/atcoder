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

ll lcm(ll a, ll b){
  return a / gcd(a, b) * b;
}

ll op(ll a, ll b){
  return gcd(a, b);
}

ll e(){
  return 0;
}

int main(){
  int n; cin >> n;
  atcoder::segtree<ll, op, e> seg(n);
  rep(i, 0, n-1) {
    ll a; cin >> a; seg.set(i, a);
  }
  
  ll ans = max(seg.prod(1, n), seg.prod(0, n-1));
  rep(i, 1, n-2){
    ll g = gcd(seg.prod(0, i), seg.prod(i+1, n));
    ans = max(ans, g);
  }

  cout << ans << endl;
}