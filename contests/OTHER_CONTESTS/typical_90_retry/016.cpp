#include <bits/stdc++.h>
#include <atcoder/all>
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

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

// ap + bq = gcd(a, b)
pll extGCD(ll a, ll b) {
    ll p11 = 1, p12 = 0, p21 = 0, p22 = 1;
    while (b) {
        ll s = a / b;
        // matrix{{0, 1}, {1, -s}}
        a -= s * b;
        swap(a, b);
 
        p11 -= s * p21;
        p12 -= s * p22;
        swap(p11, p21);
        swap(p12, p22);
    }
    return {p11, p12};
}

int main() {
  ll n; cin >> n;
  vector<ll> a(3); cin >> a[0] >> a[1] >> a[2];
  sort(all(a), greater<ll>());
  ll A = a[0], B = a[1], C = a[2];

  ll g = __gcd(B, C);
  ll BB = B/g, CC = C/g;
  auto [p, q] = extGCD(BB, CC);
  // prllf("%lld * %d + %lld * %d = 1\n", p, BB, q, CC);
  ll ans = 100000;
  for(ll i = 0; i <= 9999; i++) {
    if((n - i*A) % g > 0) continue;
    if((n - i*A) < 0) break;
    ll mul = (n - i*A) / g;
    ll pmul = p * mul;
    ll qmul = q * mul;
    if(p >= 0) {
      ll d = (-qmul + BB - 1)/BB;
      // if(qmul + d*BB < 0) d++;
      pmul -= d*CC;
      qmul += d*BB;
    }else{
      ll d = qmul / BB;
      pmul += d*CC;
      qmul -= d*BB;
    }

    if(pmul < 0 || qmul < 0) continue;

    ans = min(ans, i + pmul + qmul);
  }
  
  cout << ans << endl;
}


// int main() {
//   int n; cin >> n;
//   vector<int> a(3); cin >> a[0] >> a[1] >> a[2];
//   sort(all(a), greater<int>());

//   int ans = 100000;
//   for(int i = min(9999, n/a[0]); i >= 0; i--) {
//     if(i >= ans) continue;
//     if(i*a[0] > n) continue;
//     for(int j = 0; j <= min(9999, (n - i*a[0])/a[1]); j++) {
//       if(i+j >= ans) break;
//       if(i*a[0]+j*a[1] > n) break;
//       // if(i == 999) cout << i << " " << j << " " << (n - i*a[0])/a[1] << endl;
//       if((n - i*a[0] - j*a[1]) % a[2] == 0) {
//         if(ans > i+j+(n - i*a[0] - j*a[1])/a[2]) {
//           // cout << i << " " << j << " " << (n - i*a[0] - j*a[1])/a[2] << endl;
//           ans = i+j+(n - i*a[0] - j*a[1])/a[2];
//           // break;
//         }
//       }
//     }
//   }
//   cout << ans << endl;
// }
