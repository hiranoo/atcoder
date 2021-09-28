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
typedef pair<ll, int> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;

vector<pii> factorize(int n) {
  vector<pii> ans;
  for(int i = 2; i*i <= n; i++) {
    int idx = 0;
    while(n % i == 0) {
      idx++;
      n /= i;
    }
    if(idx > 0) ans.push_back(pii(i, idx));
  }
  if(n != 1) ans.push_back(pii(n, 1));
  return ans;
}

void show(vector<pii> f) {
  for(auto p : f) {
    cout << p.first << "^" << p.second << " & ";
  }cout << endl;
}

vector<int> make_primes(int n) {
  vector<int> ans;
  for(int i = 1; i *i <= n; i++) {
    if(n % i > 0) continue;
    ans.push_back(i);
    if(i * i != n) ans.push_back(n/i);
  }
  return ans;
}

ll lcm(int a, int b) {
  ll aa = a, bb = b;
  return aa / __gcd(aa, bb) * bb;
}


int main(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  rep(i, 0, n-1) cin >> a[i] >> b[i];

  ll ans = 0;
  for(auto x : make_primes(a[0])) for(auto y : make_primes(b[0])) {
    bool ok = true;
    rep(i, 1, n-1) {
      if( !((a[i] % x == 0 && b[i] % y == 0) || (a[i]%y==0 && b[i]%x==0)) ) {
        ok = false;
        break;
      }
    }
    if(ok) ans = max(ans, lcm(x, y));
  }

  cout << ans << endl;
}