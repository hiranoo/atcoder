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

int n, m; 

int counter(vector<ll> s, ll v) {
  int l = -1, r = m;
  while(r-l>1) {
    int x = (l+r)/2;
    if(s[x] <= v) l = x;
    else r = x;
  }
  return l;
}

int main() {
  ll k; cin >> n >> m >> k;
  vector<ll> a(n+1), b(m+1); a[0] = b[0] = 0;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, m) cin >> b[i];

  vector<ll> sum_a(n+1), sum_b(m+1);
  sum_a[0] = sum_b[0] = 0;
  rep(i, 1, n) sum_a[i] = sum_a[i-1] + a[i];
  rep(i, 1, m) sum_b[i] = sum_b[i-1] + b[i];

  int r = m;
  int ans = 0;
  for(int l = 0; l <= n; l++) {
    while(sum_a[l] + sum_b[r] > k && r > 0) r--;
    if(sum_a[l] + sum_b[r] > k) break;
    // cout << l << " " << r << endl;
    ans = max(ans, l+r);
  }

  cout << ans << endl;
}