#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template<class T> inline bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main() {
  int n; cin >> n;
  vector<ll> s(2*n), t(n);
  rep(i, 0, n-1) {
    ll v; cin >> v;
    s[i] = s[i+n] = v;
  };
  rep(i, 0, n-1) cin >> t[i];

  vector<ll> sum(2*n, 0);
  rep(i, 1, 2*n-1) sum[i] = sum[i-1] + s[i-1];
  int cur = 0;
  while(cur < n) {
    rep(j, 1, n-1) {
      if(t[cur%n]+sum[cur+j]-sum[cur] < t[(cur+j)%n]) t[(cur+j)%n] =  t[cur]+sum[cur+j]-sum[cur];
      else {
        cur += j;
        break;
      }
    }
    // cout << cur << endl;
  }

  for(auto v : t) cout << v << endl;
}