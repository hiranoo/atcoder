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

int lis(vector<int> &a) {
  int n = a.size();
  vector<int> dp(n, 1001001001);
  for(auto aa : a) {
    auto itr = lower_bound(all(dp), aa);
    *itr = aa;
  }
  return lower_bound(all(dp), 1001001001) - dp.begin();
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  int ans = n - lis(a);
  cout << ans << endl;
}