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
// const ll MOD = 1e9+7;
const ll INF = 1e18;

struct P {
  int a, b, c, d;
  P(){}
  P(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
};

int main() {
 int n, m; cin >> n >> m;
 int k; cin >> k;
 vector<string> area(n);
 vector<P> target(k);
 rep(i, 0, n-1) cin >> area[i];
 rep(i, 0, k-1) {
   int a, b, c, d; cin >> a >> b >> c >> d;
   // a--; b--; c--; d--;
   target[i] = P(a, b, c, d);
 }

 string s = "JOI";
 vector<vector<vector<int>>> sum(3, vector<vector<int>>(n+1, vector<int>(m+1, 0)));
 rep(y, 1, n) rep(x, 1, m) rep(z, 0, 2) {
   if(y) sum[z][y][x] += sum[z][y-1][x];
   if(x) sum[z][y][x] += sum[z][y][x-1];
   if(y>0 && x>0) sum[z][y][x] -= sum[z][y-1][x-1];
   if(area[y-1][x-1] == s[z]) sum[z][y][x]++;
 }

//  rep(y, 1, n) {
//    rep(x, 1, m) {
//     cout << sum[0][y][x] << " ";
//    }
//    cout << endl;
//  }

 for(auto p : target) {
    rep(z, 0, 2) {
      int res = sum[z][p.c][p.d] - sum[z][p.c][p.b-1] - sum[z][p.a-1][p.d] + sum[z][p.a-1][p.b-1];
      cout << res;
      if(z < 2) cout << " ";
      else cout << endl;
    }
 }
}
