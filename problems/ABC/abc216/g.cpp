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
// const ll MOD = 1e9+7;
const ll MOD = 998244353;
const ll INF = 1e16;

void chmax(ll &a, ll b) {a = max(a, b);}
void chmin(ll &a, ll b) {a = min(a, b);}

int op_sum(int x, int y) {return x+y;}
int op_pos(int x, int y) {return max(x, y);}
int e_sum() {return 0;}
int e_pos() {return -1;}

int main() {
  int n, m; cin >> n >> m;
  vector<int> L(m), R(m), X(m);
  rep(i, 0, m-1) cin >> L[i] >> R[i] >> X[i], L[i]--;

  vector<int> idx(m);
  rep(i, 0, m-1) idx[i] = i;

  sort(all(idx), [&](int x, int y) {return R[x] < R[y];});

  vector<int> A(n, 0);
  atcoder::segtree<int, op_sum, e_sum> seg_sum(n);
  atcoder::segtree<int, op_pos, e_pos> seg_pos(n);
  rep(i, 0, n-1) seg_pos.set(i, i);

  for(int i : idx) {
    int k = X[i] - seg_sum.prod(L[i], R[i]);
    rep(j, 0, k-1) {
      int p = seg_pos.prod(L[i], R[i]);
      A[p] = 1;
      seg_pos.set(p, -1);
      seg_sum.set(p, 1);
    }
  }

  rep(i, 0, n-1) cout << (i==0? "": " ") << A[i]; cout << endl;
}