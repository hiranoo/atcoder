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
const ll INF = 1e16;

void chmax(ll &a, ll b) {a = max(a, b);}
void chmin(ll &a, ll b) {a = min(a, b);}

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  vector<int> t(n);
  rep(i, 0, n-1) cin >> a[i] >> t[i];

  ll s = 0;
  rep(i, 0, n-1) if(t[i] == 1) s += a[i];

  ll l = -INF, r = INF;
  rep(i, 0, n-1) {
    if(t[i] == 1) l += a[i], r += a[i];
    if(t[i] == 2) l = max(l, a[i]), r = max(r, a[i]);
    if(t[i] == 3) l = min(l, a[i]), r = min(r, a[i]);
  }

  int q; cin >> q;
  rep(i, 0, q-1) {
    ll x; cin >> x;
    x += s;
    x = max(l, x);
    x = min(r, x);
    cout << x << endl;
  }
}

// int main() {
//   int n; cin >> n;
//   ll a1, b1, c1;
//   rep(i, 0, n-1) {
//     ll aa, t; cin >> aa >> t;
//     if(i == 0) {
//       switch(t) {
//         case 1:
//           a1 = aa;
//           b1 = -INF;
//           c1 = INF;
//           break;
//         case 2:
//           a1 = 0;
//           b1 = aa;
//           c1 = INF;
//           break;
//         case 3:
//           a1 = 0;
//           b1 = -INF;
//           c1 = aa;
//           break;
//       }
//     }else{
//       ll a2, b2, c2;
//       switch(t) {
//         case 1:
//           a2 = aa;
//           b2 = -INF;
//           c2 = INF;
//           break;
//         case 2:
//           a2 = 0;
//           b2 = aa;
//           c2 = INF;
//           break;
//         case 3:
//           a2 = 0;
//           b2 = -INF;
//           c2 = aa;
//           break;
//       }
//       ll a = a1+a2;
//       ll b = max(b2, b1+a2);
//       ll c = min(c2, max(b2, c1+a2));
//       a1 = a, b1 = b, c1 = c;
//     }
//   }

//   int q; cin >> q;
//   rep(i, 1, q) {
//     ll x; cin >> x;
//     cout << min(c1, max(b1, x + a1)) << endl;
//   }
// }