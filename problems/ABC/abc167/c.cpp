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
const int INF = 1001001001;

int main() {
  int n, m, x; cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, 0, n-1) rep(j, 0, m) {
    if(j==0) cin >> c[i];
    else cin >> a[i][j-1];
  }

  int ans = INF;
  rep(s, 0, (1<<n)-1) {
    int tot = 0;
    vector<int> skill(m, 0);
    rep(i, 0, n-1) if(s>>i & 1) {
      tot += c[i];
      rep(j, 0, m-1) skill[j] += a[i][j];
    }

    bool enough = true;
    for(auto v : skill) if(v < x) enough = false;
    if(enough) ans = min(ans, tot);
  }

  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}