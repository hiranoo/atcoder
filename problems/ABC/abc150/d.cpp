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

ll lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}

int main() {
  int n, m; cin >> n >> m;
  vector<ll> a(n);
  rep(i, 0, n-1) {
    int v; cin >> v;
    a[i] = v/2;
  }

  ll xmin = a[0];
  rep(i, 1, n-1) {
    ll ret = lcm(xmin, a[i]);
    if((ret/xmin)%2==0 || (ret/a[i])%2==0) {
      cout << 0 << endl;
      return 0;
    }
    xmin = ret;
  }

  ll res = m/xmin;
  if(res%2==0) res--;
  cout << (res+1)/2LL << endl;
}