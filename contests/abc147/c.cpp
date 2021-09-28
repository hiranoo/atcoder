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
  int n; cin >> n;
  vector<vector<pii>> r(n);
  rep(i, 0, n-1) {
    int a; cin >> a;
    rep(j, 0, a-1) {
      int x, y; cin >> x >> y; x--;
      r[i].push_back(pii(x, y));
    }
  }

  int ans = 0;

  rep(s, 0, (1<<n)-1) {
    int tot = 0;
    bool ng = false;
    rep(i, 0, n-1) if(s>>i & 1) {
      tot++;
      for(auto v : r[i]) {
        if((s>>v.first & 1) && v.second != 1) ng = true;
        if(!(s>>v.first & 1) && v.second == 1) ng = true;
      }
    }
    if(!ng) ans = max(ans, tot);
  }

  cout << ans << endl;
}