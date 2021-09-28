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

ll solve(ll x, ll y, ll r, ll by) {
  ll uy = y + r;
  if(uy%10000 != 0) uy = uy/10000 * 10000;
  ll lt = 0, rt = 1;
  ll ans = 0;

  auto ok = [] (ll x, ll y, ll r) {
    return x*x + y*y <= r*r;
  };

  for(ll iy = uy; iy >= by; iy -= 10000) {
    while(ok(rt*10000-x, iy-y, r)) rt++;
    while(ok(lt*10000-x, iy-y, r)) lt--;
    ans += rt - lt - 1;
  }

  return ans;
}

int main() {
  double X, Y, R;
  cin >> X >> Y >> R;

  ll x = round(X*10000), y = round(Y*10000), r = round(R*10000);

  x %= 10000;
  y %= 10000;

  ll ans = solve(x, y, r, 10000);
  ans += solve(x, -y, r, 0);
  
  cout << ans << endl;
}
