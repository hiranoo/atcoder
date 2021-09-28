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
  ll k; cin >> k;
  vector<ll> d;
  for(ll i = 1; i * i <= k; i++) {
    if(k%i==0) {
      d.push_back(i);
      if(i*i<k) d.push_back(k/i);
    }
  }
  sort(all(d));
  // for(auto v : d) cout << v << " "; cout << endl;

  
  int n = d.size();
  ll ans = 0;
  for(auto a : d) {
    for(auto b : d) {
      if(a > b) continue;
      if((k/a) < b) continue;
      if(k % (a*b) > 0LL) continue;
      if(k/(a*b) >= b) ans++;
    }
  }

  cout << ans << endl;
}