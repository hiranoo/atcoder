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
  ll x, y, a, b;
  cin >> x >> y >> a >> b;

  ll ans = 0;
  while(1) {
    if( (a * x - x - b) < 0 && a*x < y) {
      x = a*x;
      ans++;
    }else{
      break;
    }
  }

  ans += (y-1-x) / b;
  cout << ans << endl;
}