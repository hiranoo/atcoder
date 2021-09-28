#include <bits/stdc++.h>
#include <atcoder/all>
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
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  double T, L, X, Y; int Q; cin >> T >> L >> X >> Y >> Q;
  rep(i, 0, Q-1) {
    double E; cin >> E;
    double th = E / T * 2 * M_PI;
    double x = sqrt(X*X + (Y + L/2.0*sin(th))*(Y + L/2.0*sin(th)) );
    double y = L/2.0 * (1 - cos(th));
    // cout << "theta:" << th * 180 / M_PI << " x:" << x << " y:" << y << endl;
    cout << fixed << setprecision(10) << atan2(y, x) * 180.0 / M_PI << endl;
  }

  // cout << atan2(1, sqrt(5)) * 180 / M_PI<< endl;
}