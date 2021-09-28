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
  int L, Q; cin >> L >> Q;
  set<int> cuts;
  cuts.insert(0);
  cuts.insert(L);

  rep(i, 0, Q-1) {
    int c, x; cin >> c >> x;
    if(c==1) {
      cuts.insert(x);
    }else{
      auto it = cuts.upper_bound(x);
      int ans = *it;
      it--;
      ans -= *it;
      cout << ans << endl;
    }
  }
}