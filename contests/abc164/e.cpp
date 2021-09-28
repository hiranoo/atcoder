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

struct Edge {
  ll to, a, b;
};

int main() {
  ll n, m, s; cin >> n >> m >> s;
  vector<Edge> G(n);
  rep(i, 0, m-1) {
    ll u, v, a, b; cin >> u >> v >> a >> b; u--, v--;
    G[u].push_back((Edge){v, a, b});
    G[v].push_back((Edge){u, a, b});
  }

  vector<pll> C(n);
  rep(i, 0, n-1) cin >> C[i].first >> C[i].second;

  queue<pair<int, > q; // node, 
  q.push()
}