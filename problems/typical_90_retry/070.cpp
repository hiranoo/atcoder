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
// const ll INF = 1e16;
const int INF = 1001001001;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n; cin >> n;
  vector<ll> x(n), y(n);
  rep(i, 0, n-1) cin >> x[i] >> y[i];
  sort(all(x));
  sort(all(y));

  ll X, Y;
  if(n%2 == 1) {
    X = 2*x[n/2], Y = 2*y[n/2];
  }else{
    X = x[n/2] + x[n/2 - 1];
    Y = y[n/2] + y[n/2 - 1];
  }
  rep(i, 0, n-1) x[i] *= 2, y[i] *= 2;
  
  ll ans = 0;
  rep(i, 0, n-1) ans += abs(x[i] - X) + abs(y[i] - Y);
  cout << ans / 2 << endl;
}
