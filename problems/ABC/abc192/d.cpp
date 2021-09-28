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
const ll INF = 1e18;

int d;
ll m;

ll mypow(ll a, int p) {
  ll ans = 1;
  while(p) {
    if(p & 1) ans = ans * a;
    a = a * a;
    p >>= 1;
  }
  return ans;
}

// x**p <= a 
ll mylog(double a, int p) {
  ll l = d, r = m+1;
  while(r - l > 1) {
    ll x = (l+r)/2;
    if(pow(x, p) <= a) l = x;
    else r = x;
  }

  return l;
}

double f(ull n, vector<int> &x) {
  double ans = 0;
  rep(i, 0, x.size()-1) {
    if(ans*n <= INF) ans *= n;
    else {
      return -1;
    }
    ans += x[i];
  }

  // cout << "f(" << n << ", x) : " << ans << endl;
  return ans;
}



int main() {
  string s; cin >> s;
  vector<int> x;
  d = 0;
  for(auto c : s) {
    x.push_back((int)(c-'0'));
    d = max(d, (int)(c-'0'));
  }
  cin >> m;
  int L = x.size();

  if(L==1) {
    if(x[0] <= m) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
  }

  ull l = d, r = m+1;
  while(r-l>1) {
    ull a = (l+r)/2;
    // cout << "a:" << a << endl;
    if(f(a, x) == -1) r = a;
    else if(f(a, x) > m) r = a;
    else l = a;
  }
  cout << l - d << endl;
  // ll a = mylog((double)m / x[0], L-1);
  // // cout << a << endl;
  // rep(i, 1, L-1) {
  //   if(x[i] == 0) continue;
  //   while(1) {
  //     if(a == 1) break;
  //     ll sum = 0;
  //     rep(j, 0, i) sum += x[j]*pow(a, L-1-j);
  //     if(sum <= m) break;
  //     else a--;
  //   }
  // }

  // cout << a - d << endl;
}