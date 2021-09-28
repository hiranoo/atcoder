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
// const ll INF = 1e16;
const int INF = 1001001001;

bool chmax(ll &a, ll b) {if(a < b) {a = b; return true;} return false;}
bool chmin(ll &a, ll b) {if(a > b) {a = b; return true;} return false;}

int op(int a, int b) {return min(a, b);}
int e() {return INF;};

int main() {
  int n, q; cin >> n >> q;
  atcoder::segtree<int, op, e> X(n), Y(n);
  X.set(n-2, n-1), Y.set(n-2, n-1);
  ll ans = (ll) (n-2) * (n-2);

  rep(qi, 0, q-1) {
    int t, i; cin >> t >> i; i--;
    // cout << "q:" << qi << endl;
    if(t == 1) {
      int j = X.prod(i, n-1);
      // printf("t: %d, i: %d, j: %d, Y[j]: %d\n", t, i, j, Y.get(j));
      ans -= j - 1;
      if(Y.get(j-1) > i) Y.set(j-1, i);
    }else{
      int j = Y.prod(i, n-1);
      // printf("t: %d, i: %d, j: %d, X[j]: %d\n", t, i, j, X.get(j));
      ans -= j - 1;
      if(X.get(j-1) > i) X.set(j-1, i);
    }
  }

  cout << ans << endl;
}