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
const ll INF = 1e18;

void factorize(int n) {
  for(int i = 2; i*i <= n; i++) {
    int idx = 0;
    while(n%i==0) {
      idx++;
      n/= i;
    }
    if(idx) cout << i << " ** " << idx << endl;
  }
  if(n>1) cout << n << " ** " << 1 << endl;
}

ll modpow(ll a, ll p) {
  ll ans = 1;
  while(p > 0) {
    if(p & 1) ans = ans * a % MOD;
    a = a * a % MOD;
    p >>= 1;
  }
  return ans;
}

int main() {
  ll n; cin >> n;
  // factorize(n);
  
  if(n % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }

  ll a = 7;
  for(int i = 1; i <= n; i++) {
    if(a % n == 0) {
      cout << i << endl;
      return 0;
    }
    a = (10*a+7) % n;
  }

  cout << -1 << endl;
}