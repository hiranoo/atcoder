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

// t以下で最大のppの要素を求める
ll maxmin(vector<ll> &pp, ll t) {
  int l = -1, r = pp.size();
  while(r-l>1) {
    int x = (l+r)/2;
    if(pp[x] <= t) l = x;
    else r = x;
  }
  return pp[l];
}

int main() {
  int n, m; cin >> n >> m;
  vector<ll> p(n+1);
  p[0] = 0;
  rep(i, 1, n) cin >> p[i];

  vector<ll> pp;
  rep(i, 0, n) rep(j, 0, n) pp.push_back(p[i] + p[j]);
  sort(all(pp));

  ll ans = 0;
  for(auto v : pp) {
    if(v > m) continue;
    else if(v == m) {
      ans = m;
      break;
    }else{
      ans = max(ans, v + maxmin(pp, m - v));
    }
  }
  cout << ans << endl;
}