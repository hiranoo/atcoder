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
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  // sort(all(a));

  vector<int> d(1000001, 0);
  for(int x : a) {
    if(d[x]==0) for(int j = x; j < 1000001; j += x) d[j]++;
    else d[x] = 2;
  }

  int ans = 0;
  for(auto v : a) if(d[v]==1) ans++;
  cout << ans << endl;
}