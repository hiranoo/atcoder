#include <bits/stdc++.h>
#include <atcoder/segtree>
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

bool chmax(ll &a, ll b) {if(a < b) {a = b; return true;} return false;}
bool chmin(ll &a, ll b) {if(a > b) {a = b; return true;} return false;}

ll op(ll a, ll b) {return max(a, b);}
ll e() {return 0;}

int main() {
  int w, n; cin >> w >> n;
  vector<ll> L(n), R(n), V(n);
  rep(i, 0, n-1) cin >> L[i] >> R[i] >> V[i];

  // vector<atcoder::segtree<ll, op, e>> dp(n+1, atcoder::segtree<ll, op, e>(w+1));

  atcoder::segtree<ll, op, e> dp1(10005), dp2(10005);
  rep(j, L[0], R[0]) dp2.set(j, V[0]);
  
  rep(i, 1, n-1) {
    rep(j, 0, w) {
      if(i % 2 == 0) {
        ll res = dp1.get(j);
        if(L[i] <= j && j <= R[i]) chmax(res, V[i]);
        if(j-L[i]>=0) {
          ll m = dp1.prod(max(0LL, j-R[i]), max(0LL, j-L[i]+1));
          if(m > 0) chmax(res, m + V[i]);
        }
        dp2.set(j, res);
      }else{
        ll res = dp2.get(j);
        if(L[i] <= j && j <= R[i]) chmax(res, V[i]);
        if(j-L[i]>=0) {
          ll m = dp2.prod(max(0LL, j-R[i]), max(0LL, j-L[i]+1));
          if(m > 0) chmax(res, m + V[i]);
        }
        dp1.set(j, res);
      }
    }
    // cout << endl << i << " >> " << endl;
    // rep(j, 0, w) {
    //   if(i%2==0) cout << j << ":" << dp2.get(j) << " "; 
    //   else cout << j << ":" << dp1.get(j) << " "; 
    //   if(j%10==9) cout << endl;
    // }
  }

  // rep(j, 0, w) {
  //   cout << j << ":" << dp1.get(j) << " "; 
  //   if(j%10==9) cout << endl;
  // }
  // cout << endl;
  ll ans = max(dp1.get(w), dp2.get(w));
  if(ans == 0) ans = -1;
  cout << ans << endl;
}