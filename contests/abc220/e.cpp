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
const ll MOD = 998244353;
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n, d; cin >> n >> d;
  
  vector<ll> modpow(2*n + 4);
  modpow[0] = 1;
  rep(i, 1, 2*n) modpow[i] = modpow[i-1] * 2 % MOD;

  ll ans = 0;
  if(d == 1) {
    rep(i, 0, n-2) {
      ans += 2*modpow[i] % MOD;
      ans %= MOD;
    }
    ans = ans * 2 % MOD;
    cout << ans << endl;
    return 0;
  }

  rep(i, 0, n-1) {
    int dep = n-1-i;
    ll res = 0;
    if(dep >= d) {
      res += modpow[d] % MOD;
      res %= MOD;
    }
    
    if(2*dep >= d) {
      res += modpow[d-2] * (ll)min(d-1, 2*dep-d+1) % MOD;
      res %= MOD;
    }
    ans += res * modpow[i] % MOD;
    ans %= MOD;
    
  }
  ans = ans * 2 % MOD;
  cout << (ans + MOD) % MOD << endl;
}
