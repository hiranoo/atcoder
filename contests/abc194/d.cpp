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

double f(double r) {
  return 1.0 / ((1-r) * (1-r));
}

int main() {
  int n; cin >> n;
  double ans = 0;
  rep(i, 1, n-1) {
    double r = (double)(i) / n;
    ans += (1 - r) * f(r);
  }
  cout << fixed << setprecision(8) << ans << endl;
}