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
  int n, m; cin >> n >> m;
  vector<ll> h(n), w(m);
  rep(i, 0, n-1) cin >> h[i];
  rep(i, 0, m-1) cin >> w[i];
  sort(all(h));
  sort(all(w));

  vector<ll> sum1(200005, 0), sum2(200005, 0);
  for(int i = 1, cnt = 1; i < n; i += 2, cnt++) sum1[cnt] = sum1[cnt-1] + h[i] - h[i-1];
  for(int i = 2, cnt = 1; i < n; i += 2, cnt++) sum2[cnt] = sum2[cnt-1] + h[i] - h[i-1];

  // cout << "h" << " ";for(auto v : h) cout << v << " "; cout << endl;
  // cout << "w" << " ";for(auto v : w) cout << v << " "; cout << endl;
  // cout << "e" << " ";rep(i, 1, n/2) cout << sum1[i] << " "; cout << endl;
  // cout << "o" << " ";rep(i, 1, n/2) cout << sum2[i] << " "; cout << endl;

  ll ans = INF;
  for(auto v : w) {
    if(v < h[0]) chmin(ans, h[0]-v + sum2[n/2]);
    else if(h[n-1] < v) chmin(ans, sum1[n/2] + v - h[n-1]);
    else {
      int i = lower_bound(all(h), v) - h.begin() - 1;
      if(i%2==0) chmin(ans, sum1[i/2]+v-h[i]+sum2[n/2]-sum2[i/2]);
      else chmin(ans, sum1[(i+1)/2]+h[i+1]-v+sum2[n/2]-sum2[(i+1)/2]);
    }
  }
  cout << ans << endl;
}