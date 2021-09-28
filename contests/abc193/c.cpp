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

int main() {
  ll n; cin >> n;

  set<ll> s;
  for(ll i = 2; i*i <= n; i++) {
    ll x = i;
    if(s.count(x)) continue;
    for(int j = 2; j <= 33; j++) {
      x *= i;
      if(x > n) break;
      s.insert(x);
    }
  }
  cout << n - s.size() << endl;
}