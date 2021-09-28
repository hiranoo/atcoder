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
  ll n; cin >> n;
  ll ans = 0;
  for(ll i = 1; i <= n; i = i*10 + 1) {
    for(ll j = 1; i*j <= n; j *= 10) {
      ans += max(0LL, min(n-i*j+1, (i+1)*j-i*j));
    }
  }
  cout << ans << endl;
}