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

ll lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}

int main() {
  int n, m; cin >> n >> m;
  vector<ll> a(m);
  rep(i, 0, m-1) cin >> a[i];
  
  ll ans = 0;
  rep(s, 1, (1LL<<m)-1) {
    int k = 0;
    rep(i, 0, m-1) if(s & 1LL<<i) k++;
    ll l = 1;
    rep(i, 0, m-1) if(s & 1LL<<i) l = lcm(l, a[i]);
    if(k%2==0) ans -= n/l;
    else ans += n/l;
  }
  cout << ans << endl;
}