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

struct P {
  int a, b, c;
  P(){}
  P(int a, int b, int c) : a(a), b(b), c(c) {}
};

int main() {
  int n, m; cin >> n >> m;
  vector<vector<ll>> sum(n+1, vector<ll>(n+1, 0));
  rep(i, 0, m-1) {
    int a, b, x; cin >> a >> b >> x; a--; b--;
    rep(k, 0, x) {
      sum[a-b+k][b]++;
      sum[a-b+k][b+x+1-k]--;
    }
  }

  ll ans = 0;
  rep(y, 0, n-1) {
    ll s = 0;
    rep(x, 0, n-1) {
      sum[y][x] += sum
    }
  }
  cout << ans << endl;
}