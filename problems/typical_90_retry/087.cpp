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

vector<vector<ll>> warshall_floyd(vector<vector<ll>> cost, ll x) {
  int n = cost.size();
  vector<vector<ll>> d = cost;
  rep(i, 0, n-1) rep(j, 0, n-1) if(d[i][j] == INF) d[i][j] = x;

  rep(k, 0, n-1) rep(i, 0, n-1) rep(j, 0, n-1) {
    chmin(d[i][j], d[i][k] + d[k][j]);
  }

  return d;
}

int main() {
  int n, P, K; cin >> n >> P >> K;
  vector<vector<ll>> cost(n, vector<ll>(n, INF));

  rep(i, 0, n-1) rep(j, 0, n-1) {
    ll v; cin >> v; if(v != -1) cost[i][j] = v;
  }

  vector<vector<ll>> d = warshall_floyd(cost, INF);

  // rep(i, 0, n-1) {
  //   rep(j, 0, n-1) cout << d[i][j] << " "; cout << endl;
  // }
  int cnt = 0;
  rep(i, 0, n-1) rep(j, i+1, n-1) if(d[i][j] <= P) cnt++;
  // cout << "cnt: " << cnt << endl;
  if(cnt > K) {
    cout << 0 << endl;
    return 0;
  }else if(cnt == K) {
    cout << "Infinity" << endl;
    return 0;
  }

  auto f = [&](ll x) {
    vector<vector<ll>> d = warshall_floyd(cost, x);
    int c = 0;
    rep(i, 0, n-1) rep(j, i+1, n-1) if(d[i][j] <= P) c++;
    return c;
  };

  ll l = 0, r = INF;
  while(r-l > 1) {
    ll t = (l+r) / 2;

    if(f(t) >= K) l = t;
    else r = t;
  }

  ll ans = l;
  if(f(r) == K) ans = r;

  r = l, l = 0;
  while(r-l> 1 ) {
    ll t = (l+r) / 2;

    if(f(t) >= K+1) l = t;
    else r = t;
  }

  if(f(r) == K) ans = ans - r + 1;
  else ans = ans - r;
  cout << ans << endl;
}