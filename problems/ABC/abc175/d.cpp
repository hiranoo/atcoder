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
  int n, k; cin >> n >> k;
  vector<int> p(n);
  vector<ll> c(n);
  rep(i, 0, n-1) cin >> p[i], p[i]--;
  rep(i, 0, n-1) cin >> c[i];

  ll ans = -INF;
  rep(i, 0, n-1) {
    int nxt = p[i];
    vector<ll> sum;
    sum.push_back(c[nxt]);
    while(nxt != i) {
      nxt = p[nxt];
      sum.push_back(c[nxt] + sum[sum.size()-1]);
    }
    int len = sum.size();
    if(k <= len) {
      rep(i, 0, k-1) chmax(ans, sum[i]);
    }else if(sum[len-1] <= 0) {
      rep(i, 0, len-1) chmax(ans, sum[i]);
    }else{
      if(k%len != 0) {
        ll res = sum[len-1] * (ll)(k/len);
        ll ma = -INF;
        rep(i, 0, k%len-1) chmax(ma, sum[i]);
        if(ma != -INF) res += ma;
        
        chmax(ans, res);
      }else{
        ll res = sum[len-1] * (ll)(k/len-1);
        ll ma = -INF;
        rep(i, 0, len-1) chmax(ma, sum[i]);
        if(ma != -INF) res += ma;
        
        chmax(ans, res);
      }
    }
  }

  cout << ans << endl;
}