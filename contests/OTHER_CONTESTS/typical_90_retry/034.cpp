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
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e16;

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  map<int, int> mp;
  int ans = 0;
  int r = 0;
  rep(l, 0, n-1) {
    // cout << "l:" << l << " r:" << r << " -> ";
    while(r < n && mp.size() <= k) mp[a[r]]++, r++;
    // cout << r << endl;
    if(mp.size() <= k) ans = max(ans, r-l);
    else ans = max(ans, r-l-1);
    mp[a[l]]--;
    if(mp[a[l]] == 0) mp.erase(a[l]);
  }

  cout << ans << endl;
}