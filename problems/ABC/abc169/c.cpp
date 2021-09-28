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
const int INF = 1001001001;

int main() {
  ll a; cin >> a;
  string b; cin >> b;
  int x, y;
  x = (int)(b[0] - '0');
  y = (int)(b[2] - '0') * 10 + (int)(b[3] - '0');

  ll ans = a * x;
  // ans += (a/10) * (y/10);
  // ans += (a/100) * (y%10);
  ans += (a*y)/100;
  cout << fixed << setprecision(17) << ans << endl;
}