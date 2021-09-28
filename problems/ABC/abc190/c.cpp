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
  int n, m; cin >> n >> m;
  vector<vector<int>> ok(101, vector<int>(101, 0));
  rep(i, 0, m-1) {
    int a, b; cin >> a >> b; a--; b--;
    ok[a][b]++;
  }

  int K; cin >> K;
  vector<pii> ball(K);
  rep(i, 0, K-1) {
    int a, b; cin >> a >> b; a--; b--;
    ball[i] = pii(a, b);
  }

  int ans = 0;
  rep(s, 0, (1<<K)-1) {
    vector<bool> used(n, false);
    rep(i, 0, K-1) {
      if(s & (1<<i)) used[ball[i].first] = true;
      else used[ball[i].second] = true;
    }
    int res = 0;
    rep(i, 0, n-1) rep(j, i+1, n-1) if(used[i]&&used[j]) res += ok[i][j];
    ans = max(ans, res);
  }
  cout << ans << endl;
}