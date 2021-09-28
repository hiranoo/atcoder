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

int main(){
  int n, k; cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  ll ans = INF;
  rep(i, 0, (1<<n)) {
    int cnt = 1;
    ll cost = 0;
    int cur_h = a[0];
    bool ok = true;
    rep(j, 1, n-1) {
      if(i & (1<<j)) {
        if(cur_h < a[j]) {
          ok = false;
          break;
        }
        cur_h++;
        cost += cur_h - a[j];
        cnt++;
      }else{
        if(cur_h < a[j]) {
          cur_h = a[j];
          cnt++;
        }
      }
    }
    if(ok && cnt >= k) ans = min(ans, cost);
  }

  cout << ans << endl;
}