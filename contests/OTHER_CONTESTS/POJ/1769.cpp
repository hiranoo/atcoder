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

int op(int a, int b) {return min(a, b);}
int e() {return 1001001001;}

int main() {
  int n, m; cin >> n >> m;
  vector<int> s(m), t(m);
  rep(i, 0, m-1) {
    int a, b; cin >> a >> b; a--; b--;
    s[i] = a; t[i] = b;
  }

  atcoder::segtree<int, op, e> dp(n+1);
  dp.set(0, 0);
  rep(i, 0, m-1) {
    if(dp.get(t[i]) > dp.prod(s[i], t[i]) + 1) dp.set(t[i], dp.prod(s[i], t[i]) + 1);
  }

  cout << dp.get(n-1) << endl;
}