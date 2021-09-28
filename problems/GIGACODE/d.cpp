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

void chmin(ll &a, ll b) {
  if(a > b) a = b;
}

int main() {
  int h, w; ll K, V; cin >> h >> w >> K >> V;
  vector<vector<ll>> area(h+1, vector<ll>(w+1, 0)), sum(h+1, vector<ll>(w+1, 0));
  rep(y, 1, h) rep(x, 1, w) cin >> area[y][x];

  rep(y, 1, h) rep(x, 1, w) {
    sum[y][x] += sum[y-1][x];
    sum[y][x] += sum[y][x-1];
    sum[y][x] -= sum[y-1][x-1];
    sum[y][x] += area[y][x];
  }

  map<int, ll> mp;
  rep(sy, 1, h) rep(sx, 1, w) {
    ll res = INF;
    rep(y, 0, h-sy) rep(x, 0, w-sx) {
      chmin(res, sy*sx*K + sum[y+sy][x+sx] - sum[y+sy][x] - sum[y][x+sx] + sum[y][x]);
    }
    if(mp.count(sy*sx) > 0) chmin(mp[sy*sx], res);
    else mp[sy*sx] = res;
  }

  int ans = 0;
  for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
    // cout << itr->first << ": " << itr->second << endl;
    if(itr->second <= V && ans <= itr->first) {
      ans = itr->first;
    } 
  }
  cout << ans << endl;
}