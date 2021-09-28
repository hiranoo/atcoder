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

int main() {
  string s; cin >> s;
  int n = s.size();
  int m = 2019;
  vector<int> mpow(n);
  mpow[0] = 1;
  rep(i, 1, n-1) mpow[i] = mpow[i-1] * 10 % m;

  reverse(all(s));
  vector<int> sum(n+1);
  sum[0] = 0;
  rep(i, 1, n) sum[i] = ( sum[i-1] + mpow[i-1]*(s[i-1] - '0') ) % m;
  // for(int i = n; i > 0; --i) cout << sum[i] << " "; cout << endl;

  map<int, int> mp;
  ll ans = 0;
  rep(i, 0, n) {
    // cout << i << " " << mp[sum[i] - '0'] << endl;
    ans += mp[sum[i]-'0']++;
  }
  cout << ans << endl;
}