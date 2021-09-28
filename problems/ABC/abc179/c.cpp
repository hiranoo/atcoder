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

ll f(int k) {
  ll ans = 0;
  for(int d = 1; d*d <= k; d++) {
    if(k % d == 0) {
      ans++;
      if(d*d != k) ans++;
    }
  }
  return ans;
}

int main() {
  int n; cin >> n;
  ll ans = 0;
  rep(c, 1, n-1) {
    ans += f(n-c);
  }

  cout << ans << endl;
}