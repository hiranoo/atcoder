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
  int k; cin >> k;
  string a, b; cin >> a >> b;
  ll ans = 1;
  
  auto f = [&] (string s) {
    ll res = 0;
    rep(i, 0, s.size()-1) {
      res += (ll)(s[i]-'0') * pow(k, s.size()-i-1);
    }
    return res;
  };

  cout << f(a) * f(b) << endl;

}