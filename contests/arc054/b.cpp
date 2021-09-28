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

double f(double x, double p) {
  return x + p * pow(2.0, -x/1.5);
}

// double df(double x, double p) {
//   return 1.0 - 2.0/3.0 * 0.30102999566 * p * pow(2.0, -x/1.5);
// }

int main() {
  double p; cin >> p;
  double lt = 0, rt = 1e100;

  while(rt - lt > 0.00000000001) {
    double c1 = (lt*2.0+rt)/3.0, c2 = (lt+rt*2.0)/3.0;
    if(f(c1, p) > f(c2, p)) lt = c1;
    else rt = c2;
    // double x = (lt+rt)/2.0;
    // if(f(lt, p) > f(rt, p)) lt = x;
    // else rt = x;
  }
  cout << fixed << setprecision(10) << f(lt, p) << endl;
}