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
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e16;

int op(int a, int b) {
  return max(a, b);
}

int e() {
  return 0;
}

int main() {
  int w, n; cin >> w >> n;
  atcoder::segtree<int, op, e> seg(w+1);

  rep(i, 0, n-1) {
    int l, r; cin >> l >> r;
    int t = seg.prod(l, r+1);
    seg.set(l, t+1);
    set.set(r, t+1);
  }
}