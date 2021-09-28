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
  int n; ll k; cin >> n >> k;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];
  a.push_back(0);
  sort(all(a), greater<ll>());

  ll j = 1, cnt = 0, ans = 0;
  rep(i, 0, n-1) {
    ll diff = a[i] - a[i+1];
    if(cnt + diff * j <= k) {
      ans += (a[i]+a[i+1]+1) * diff / 2 * j;
      cnt += diff * j++;
    }else{
      ll q = (k - cnt) / j;
      ll r = (k - cnt) % j;
      ans += (a[i]+a[i]-q+1) * q / 2 * j;
      ans += (a[i]-q) * r;
      break;
    }
  }

  cout << ans << endl;
}


// int main() {
//   int n; ll k; cin >> n >> k;
//   vector<ll> a(n);
//   map<ll, int> mp;
//   rep(i, 0, n-1) cin >> a[i];

//   sort(all(a));
//   reverse(all(a));
//   ll max_a = a[0];

//   for(auto v : a) {
//     mp[-v]++;
//   }
//   mp[0]++;
  
//   ll ans = 0; 
//   ll i = 0;
//   ll cnt = 0;
//   ll pre = 0;
//   for(auto it : mp) {
//     ll dif = max(0LL, pre - (-it.first));
//     // printf("from: %lld -- to: %lld, dif= %lld, x %d個, cnt=%lld, ans=%lld\n", pre, -it.first, pre+it.first, i, cnt, ans);
//     if(cnt + dif * i <= k) {
//       if(pre != 0) {
//         cnt += dif * i;
//         ans += (pre + (-it.first)+1) * dif /2LL * i;
//       }
//     }else{
//       ll b = k - cnt;
//       if(b%i == 0) ans += (pre + pre - (b/i)+1) * (b/i) / 2LL * i;
//       else{
//         ans += (pre + pre - (b/i)+1) * (b/i) / 2LL * i;
//         ans += (pre - (b/i)) * (b%i);
//       }
//       break;
//     }

//     i += it.second;
//     pre = -it.first;
//   }

//   cout << ans << endl;
// }