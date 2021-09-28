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

bool chmax(ll &a, ll b) {if(a < b) {a = b; return true;} return false;}
bool chmin(ll &a, ll b) {if(a > b) {a = b; return true;} return false;}

int main() {
  ll n, x, m; cin >> n >> x >> m;
  vector<ll> f;
  vector<int> used(m, -1);
  
  ll s = n, c = 1;
  rep(i, 0, n-1) {
    if(used[x] != -1) {
      s = used[x];
      c = i - s;
      break;
    }
    used[x] = i;
    f.push_back(x);
    x = x * x % m;
  }

  ll ans = 0;
  rep(i, 0, s-1) ans += f[i];

  ll sum = 0;
  rep(i, s, f.size()-1) sum += f[i];

  ll q = (n-s) / c;
  ll r = (n-s) % c;
  ans += sum * q;
  rep(i, s, s+r-1) ans += f[i];

  cout << ans << endl;
}

// int main() {
//   ll n, x, m; cin >> n >> x >> m;
//   ll _x = x;

//   vector<ll> come(m, 0);
//   ll cnt = 1;
//   while(come[x] == 0 && cnt <= n) {
//     come[x] = cnt;
//     x = x * x % m;
//     cnt++;
//   }

//   // cout << "cnt: " << cnt << endl;
//   // cout << "x: " << x << endl;
//   // rep(i, 0, m-1) if(come[i]) cout << i << " : " << come[i] << endl;
//   ll ans = 0;
//   if(cnt > n) {
//     rep(i, 0, m-1) if(come[i] > 0) ans += i;
//     cout << ans << endl;
//     return 0;
//   }

//   // in cycle
//   vector<ll> cycle;
//   bool in_cycle = false;
//   while(1) {
//     if(!in_cycle && _x == x) in_cycle = true;
//     else if(in_cycle && _x == x) break;

//     if(in_cycle) cycle.push_back(_x);
//     if(!in_cycle) ans += _x;
//     _x = _x * _x % m;
//   }

//   // before cycle
//   // cout << "pre ans: " << ans << endl;
//   ll pre = come[x] - 1;


//   ll sum = 0;
//   for(ll v : cycle) sum += v;

//   ll q = (n-pre) / (ll)cycle.size();
//   ll r = (n-pre) % (ll)cycle.size(); 
//   ans += sum * q;
  
//   rep(i, 0, r-1) {
//     ans += cycle[i];
//   }

//   cout << ans << endl;
// }