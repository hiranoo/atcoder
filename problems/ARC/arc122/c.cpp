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
const ll INF = 1e18;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  ll n; cin >> n;
  if(n == 1) {
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }
  if(n == 2) {
    cout << 2 << endl;
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }

  vector<ll> f(130);
  f[0] = 0, f[1] = 1;
  rep(i, 2, 130) f[i] = f[i-1] + f[i-2];

  int m = lower_bound(all(f), n)-f.begin();
  if(f[m] == n) {
    if(m%2!=0) {
      cout << m-1 << endl;
      cout << 1 << endl;
      rep(i, 1, m/2)cout << 4 << endl << 3 << endl;
    }else {
      cout << m-1 << endl;
      cout << 2 << endl;
      rep(i, 1, m/2-1) cout << 3 << endl << 4 << endl;
      cout << 3 << endl;
    }
    return 0;
  }


  ll x = n/f[m-2], y = 0;
  y = (n-f[m-2]*x)/f[m-3];
  // while(f[m-2]*x + f[m-3]*y > n) x--, y++;
  printf("%lld * %lld + %lld * %lld = %lld\n", f[m-2], x, f[m-3], y, f[m-2]*x + f[m-3]*y);
}