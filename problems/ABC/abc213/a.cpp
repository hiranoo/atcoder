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
const ll INF = 1e18;

int main() {
  int a, b; cin >> a >> b;
  int ans = 0;
  rep(s, 0, 255) {
    rep(i, 0, 7) {
      if(bitset<8>(a).test(i) && !bitset<8>(b).test(i)) ans |= 1 << i;
      if(!bitset<8>(a).test(i) && bitset<8>(b).test(i)) ans |= 1 << i;
    }
  }
  cout << ans << endl;
}