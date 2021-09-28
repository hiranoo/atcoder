#include <bits/stdc++.h>
#include <atcoder/all>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template<class T> inline bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main() {
  int n; cin >> n;
  vector<pair<int, pii>> es;
  rep(i, 1, n-1) {
    int u, v, w; cin >> u >> v >> w;
    --u; --v;
    es.emplace_back(w, pii(u, v));
  }
  sort(all(es));
  atcoder::dsu d(n);
  ll ans = 0;
  for(auto e : es) {
    ans += (ll)(e.first) * d.size(e.second.first) * d.size(e.second.second);
    d.merge(e.second.first, e.second.second);
  }
  cout << ans << endl;
}


struct P {
  ll cost, u, v;
  P(){}
  P(ll cost, ll u, ll v) : cost(cost), u(u), v(v) {}
  bool operator< (const P &p) {
    return cost < p.cost;
  }
};