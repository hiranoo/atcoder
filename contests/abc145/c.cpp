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

double d(pii a, pii b) {
  int ret = (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
  return sqrt(ret);
}
int main(){
  int n; cin >> n;
  vector<int> x(n), y(n), idx(n);
  rep(i, 0, n-1) cin >> x[i] >> y[i];
  rep(i, 0, n-1) idx[i] = i;

  double sum = 0;
  int cnt = 0;
  do {
    // for(auto id : idx) cout << "(" << x[id] << "," << y[id] << ") -> "; cout << endl;
    cnt++;
    rep(i, 1, n-1) {
      sum += sqrt(pow(x[idx[i]] - x[idx[i-1]], 2) + pow(y[idx[i]] - y[idx[i-1]], 2));
    }
  } while(next_permutation(all(idx)));

  // cout << cnt << endl;
  double ans = sum / cnt;
  cout << fixed << setprecision(8) << ans << endl;
}