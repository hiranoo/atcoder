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
  int n; cin >> n;
  vector<ll> a(46, 0), b(46, 0), c(46, 0);
  rep(i, 0, n-1) {int v; cin >> v; a[v%46]++;}
  rep(i, 0, n-1) {int v; cin >> v; b[v%46]++;}
  rep(i, 0, n-1) {int v; cin >> v; c[v%46]++;}

  // rep(i, 0, 45) if(a[i] > 0) cout << a[i] << "(" << i << ") "; cout << endl;
  // rep(i, 0, 45) if(b[i] > 0) cout << b[i] << "(" << i << ") "; cout << endl;
  // rep(i, 0, 45) if(c[i] > 0) cout << c[i] << "(" << i << ") "; cout << endl;

  ll ans = 0;
  rep(i, 0, 45) rep(j, 0, 45) rep(k, 0, 45) {
    if((i+j+k) % 46 == 0) ans += a[i] * b[j] * c[k];
  }

  cout << ans << endl;
}