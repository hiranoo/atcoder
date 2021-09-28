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

int myceil(int v, int k) {
  if(v%k == 0) return v/k;
  return v/k+1;
}

int main() {
  int n, m; cin >> n >> m;

  vector<int> a(m+2);
  a[0] = 0; a[m+1] = n+1;
  rep(i, 1, m) cin >> a[i];
  sort(a.begin()+1, a.end()-1);

  if(n == m) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> w;
  rep(i, 1, m+1) if(a[i]-a[i-1]-1 > 0) w.push_back(a[i]-a[i-1]-1);
  // for(auto v : w) cout << v << " "; cout << endl;

  if(w.size() == 0) {
    cout << 0 << endl;
    return 0;
  }

  sort(all(w));
  int k = w[0];

  ll ans = 0;
  for(auto v : w) {
    ans += myceil(v, k);
  }
  cout << ans << endl;
}