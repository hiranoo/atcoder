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
const int MAX_N = 1005;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

ll op(ll a, ll b) {
  return a+b;
}
ll e() {
  return 0;
}

int main() {
  int n, m; cin >> n >> m;
  vector<pii> vs(m);
  rep(i, 0, m-1) {
    int l, r; cin >> l >> r; l--, r--;
    vs[i] = pii(l, r);
  }

  // connected segments
  ll ans1 = 0;
  vector<ll> cnt(n, 0);
  for(auto p : vs) cnt[p.first]++, cnt[p.second]++;
  rep(i, 0, n-1) ans1 += (ll)cnt[i]*(cnt[i]-1)/2LL;

  // subsequent segments
  ll ans2 = 0;
  vector<ll> s(n, 0);
  for(auto p : vs) s[p.second]++;
  vector<ll> ss(n, 0);
  ss[0] = s[0];
  rep(i, 1, n-1) ss[i] = ss[i-1] + s[i];
  for(auto p : vs) if(p.first-1 >= 0) ans2 += ss[p.first-1];

  // included ranges
  ll ans3 = 0;
  atcoder::segtree<ll, op, e> tree(n+1);
  auto comp = [&] (pii a, pii b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
  };
  sort(all(vs), comp);
  int tot = 0;
  for(auto [l, r] : vs) {
    ans3 += tot - tree.prod(0, l+1);
    tree.set(l, tree.get(l)+1);
    tot++;
  }

  ll ans = ans1 + ans2 + ans3;
  ans = (ll)m*(m-1)/2 - ans;
  cout << ans << endl;
}


// int main() {
//   int n, m; cin >> n >> m;
//   vector<pii> seg(m);
//   rep(i, 0, m-1) cin >> seg[i].first >> seg[i].second;

//   ll ans = 0;
//   rep(i, 0, m-1) rep(j, i+1, m-1) {
//     if(seg[i].first<seg[j].first && seg[j].first<seg[i].second && seg[i].second<seg[j].second) ans++;
//     if(seg[j].first<seg[i].first && seg[i].first<seg[j].second && seg[j].second<seg[i].second) ans++;
//   }

//   cout << ans << endl;
// }