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
// const ll INF = 1e16;

bool ok = false;
struct P {
  int x, y;
  P() {}
  P(int x, int y) : x(x), y(y) {}
  bool operator< (const P &p) {
    if(x == p.x) return y < p.y;
    return x < p.x;
  }
};


int main() {
  int n; cin >> n;
  vector<P> vs;
  rep(i, 0, n-1) {
    int x, y; cin >> x >> y;
    vs.push_back(P(x, y));
  }

  sort(all(vs));

  const int INF = 1001001001;
  int l = 0, r = INF;
  while(r-l > 1) {
    int d = (l + r) / 2;
    auto f = [&](int d) {
      int j = 0;
      int ymin = INF, ymax = -INF;
      rep(i, 0, n-1) {
        int x = vs[i].x, y = vs[i].y;
        while(j < i && vs[j].x <= x - d) {
          ymin = min(ymin, vs[j].y);
          ymax = max(ymax, vs[j].y);
          j++;
        }
        if(ymax - y >= d) return true;
        if(y - ymin >= d) return true;
      }
      return false;
    };
    if(f(d)) l = d;
    else r = d;
  }

  cout << l << endl;
}
