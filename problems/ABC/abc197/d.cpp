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
// const ll INF = 1e18;

struct P {
  double a, b;
  P(){}
  P(double a, double b) : a(a), b(b) {}
  P operator* (const P &p) {
    return P(a*p.a-b*p.b, a*p.b+b*p.a);
  }
  P operator+ (const P &p) {
    return P(a+p.a, b+p.b);
  }
  P operator- (const P &p) {
    return P(a-p.a, b-p.b);
  }
  P operator/ (int d) {
    return P(a/d, b/d);
  }
};

int main() {
  int n; cin >> n;
  P x, y, c;
  cin >> x.a >> x.b;
  cin >> y.a >> y.b;
  c = (x + y) / 2;
  x = x - c;
  double th = 2*M_PI/(double)n;
  x = x * P(cos(th), sin(th));
  x = x + c;
  cout << fixed << setprecision(8) << x.a << " " << x.b << endl;
}