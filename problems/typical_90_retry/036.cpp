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
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  ll n, q; cin >> n >> q;
  vector<pll> p(n);
  rep(i, 0, n-1) cin >> p[i].first >> p[i].second;

  ll min_a = INF, min_b = INF, max_a = -INF, max_b = -INF;
  for(auto [x, y] : p) {
    chmin(min_a, x+y);
    chmin(min_b, x-y);
    chmax(max_a, x+y);
    chmax(max_b, x-y);
  }

  rep(qi, 0, q-1) {
    ll i; cin >> i; i--;
    ll ans = 0;
    chmax(ans, max_a - (p[i].first + p[i].second));
    chmax(ans, max_b - (p[i].first - p[i].second));
    chmax(ans, p[i].first + p[i].second - min_a);
    chmax(ans, p[i].first - p[i].second - min_b);
    cout << ans << endl;
  }
}
