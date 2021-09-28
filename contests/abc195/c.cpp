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
  int len = s.size();
  
  ll ans = (ll)(len%3==0? len/3-1: len/3) * (stoll(s) - (ll)pow(10, len-1) + 1);

  for(int k = len-1; k >= 0; k--) {
    ll res = 9 * pow(10, k-1) * (k%3==0? k/3-1 : k/3);
    // cout << k << " " << res << endl;
    ans += res;
  }

  cout << ans << endl;
}