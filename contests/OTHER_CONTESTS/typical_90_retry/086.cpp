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
// const ll INF = 1e16;
const int INF = 1001001001;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n, q; cin >> n >> q;
  vector<ll> x(q), y(q), z(q), w(q);
  rep(i, 0, q-1) cin >> x[i] >> y[i] >> z[i] >> w[i], x[i]--, y[i]--, z[i]--;

  ll ans = 1;

  rep(j, 0, 59) {
    ll res = 0;
    rep(s, 0, (1<<n)-1) {
      bool ok = true;
      rep(i, 0, q-1) {
        if( ( (s>>x[i] & 1) + (s>>y[i] & 1) + (s>>z[i] & 1) ) > 0 != (w[i]>>j & 1) > 0 ) {
          ok = false;
          break;
        }
      }
      if(ok) res++;
    }
    ans = ans * res % MOD;
  }

  cout << (ans + MOD) % MOD << endl;
}
