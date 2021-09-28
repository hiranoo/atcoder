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

int main() {
  ll n; cin >> n;

  ll ans = 0;
  n *= 2;
  for(ll i = 1; i*i <= n; i++) {
    if(n%i==0 && i%2 != (n/i)%2) ans+=2;
  }

  cout << ans << endl;
}