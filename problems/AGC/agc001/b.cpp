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

ll ans = 0;

ll gcd(ll a, ll b){
  if(a < b) swap(a, b);
  if(b == 0) {
    ans -= a;
    return a;
  }
  ans += 2*(b/a)*a;
  return gcd(b, a%b);
}

ll func(ll a, ll b){
  if(a > b) return func(b, a);
  if(a == b) return a;
  if(b % a != 0) return 2*(b/a)*a + func(a, b%a);
  return (2*b/a - 1)*a;
}
int main(){
  ll n, x; cin >> n >> x;

  cout << n + func(n-x, x) << endl;
}