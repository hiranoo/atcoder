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

int main(){
  int n; cin >> n;
  vector<ll> t(n);
  rep(i, 0, n-1) cin >> t[i];

  ll ans = t[0];
  rep(i, 1, n-1){
    ans = lcm(ans, t[i]);
  }

  cout << ans << endl;
}