#include <bits/stdc++.h>
// #include <atcoder/segtree>
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

ll modpow(ll a, ll p) {
  ll ans = 1;
  int i = 0;
  while(p > 0) {
    if(p & 1) {
      ans = (ans * a) % MOD;
    }
    a = a * a % MOD;
    p >>= 1;
  }
  return ans;
}

int main() {
  ll n, m; cin >> m >> n;
  cout << modpow(m, n) << endl;
}