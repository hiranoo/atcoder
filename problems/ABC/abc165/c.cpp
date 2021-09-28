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

int n, m, q;
vector<int> a(51), b(51), c(51), d(51);
int ans = 0;
int A[10];
void dfs(int id = 0, int v = 1) {
  if(id == n) {
    int tot = 0;
    rep(i, 0, q-1) {
      if(A[b[i]] - A[a[i]] == c[i]) tot += d[i];
    }
    ans = max(ans, tot);
    return;
  }

  rep(nxt, v, m) {
    A[id] = nxt;
    dfs(id+1, nxt);
  }
}

int main() {
  cin >> n >> m >> q;
  rep(i, 0, q-1) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--; b[i]--;
  }

  dfs(0, 1);
  cout << ans << endl;
}

// struct P {
//   int a, b, c;
//   P(){}
//   P(int a, int b, int c) : a(a), b(b), c(c) {}
// };

// int main() {
//   int n, m, q; cin >> n >> m >> q;
//   vector<vector<vector<int>>> mp = vector<vector<vector<int>>>(10, vector<vector<int>>(10, vector<int>(10, 0)));
//   rep(i, 0, q-1) {
//     int a, b, c, d; cin >> a >> b >> c >> d;
//     a--; b--;
//     mp[a][b][c] = max(mp[a][b][c], d);
//   }

//   vector<int> a(10);
//   int ans = 0;
//   rep(i0, 0, m-1) rep(i1, i0, m-1) rep(i2, i1, m-1) rep(i3, i2, m-1) rep(i4, i3, m-1) rep(i5, i4, m-1) rep(i6, i5, m-1) rep(i7, i6, m-1) rep(i8, i7, m-1) rep(i9, i8, m-1) {
//     a[0] = i0;
//     a[1] = i1;
//     a[2] = i2;
//     a[3] = i3;
//     a[4] = i4;
//     a[5] = i5;
//     a[6] = i6;
//     a[7] = i7;
//     a[8] = i8;
//     a[9] = i9;
//     int res = 0;
//     rep(i, 0, n-2) rep(j, i+1, n-1) {
//       res += mp[i][j][ a[j]-a[i] ];
//     }
//     ans = max(ans, res);
//   }
//   cout << ans << endl;
// }