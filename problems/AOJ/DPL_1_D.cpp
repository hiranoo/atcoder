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
const ll INF = 1e18;

int lis_bs(vector<ll> &a) {
  int n = a.size();
  vector<ll> dp(n, INF);
  for(auto v : a) {
    auto it = lower_bound(all(dp), v);
    *it = v;
  }
  return lower_bound(all(dp), INF) - dp.begin();
}


int op(int a, int b) {
  if(a > b) return a;
  return b;
}

int e() {
  return 0;
}

int lis_seg(vector<ll> &a) {
  int n = a.size();
  //　座標圧縮 range(a)をnに抑える
  map<ll, int> mp;
  rep(i, 0, n-1) mp[a[i]]++;
  int i = 1;
  for(auto itr = mp.begin(); itr != mp.end(); itr++) {
    itr->second = i++;
  }

  vector<int> b(n);
  rep(i, 0, n-1) b[i] = mp[a[i]];

  // for(auto v : b) cout << v << " "; cout << endl;

  atcoder::segtree<int, op, e> seg(n+1);
  rep(i, 0, n-1) {
    // cout << "set " << b[i] << " ";
    seg.set(b[i], seg.prod(0, b[i])+1);
    // cout << "check " << seg.get(b[i]) << endl;
    // rep(k, 0, n) cout << seg.get(k) << ", "; cout << endl << endl;
  }

  int ans = seg.all_prod();

  // rep(i, 0, n-1) cout << seg.get(b[i]) << " "; cout << endl;

  return ans;
}

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];

  // cout << lis_bs(a) << endl;
  cout << lis_seg(a) << endl;
}