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
  int x, n; cin >> x >> n;
  if(n==0) {
    cout << x << endl;
    return 0;
  }
  vector<int> p(n);
  rep(i, 0, n-1) cin >> p[i];
  sort(all(p));

  rep(i, 0, 300) {
    if(*lower_bound(all(p), x-i) != x-i) {
      cout << x-i << endl;
      return 0;
    }
    if(*lower_bound(all(p), x+i) != x+i) {
      cout << x+i << endl;
      return 0;
    }
  }
}