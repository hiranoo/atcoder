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



int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];
  set<int> s;
  rep(i, 0, n-1) {
    auto itr = lower_bound(all(s), a[i]);
    if(itr == s.begin()) s.insert(a[i]);
    else {
      itr--;
      s.erase(itr);
      s.insert(a[i]);
    }
  }
  int ans = s.size();
  // deque<int> d;

  // rep(i, 0, n-1) {
  //   int p = lower_bound(all(d), a[i]) - d.begin();
  //   if(p==0) d.push_front(a[i]);
  //   else d[p-1] = a[i];
  // }
  // int ans = d.size();
  cout << ans << endl;
}