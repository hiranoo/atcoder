#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
//#include <atcoder/segtree>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// typedef pair<ll, int> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> ss(m, vector<int>(n, 0));
  vector<int> pp(m);
  rep(i, 0, m-1) {
    int k; cin >> k;
    rep(kk, 0, k-1) {
      int s; cin >> s;
      ss[i][s-1] = 1;
    }
  }
  rep(i, 0, m-1) cin >> pp[i];

  int ans = 0;
  rep(i, 0, (1 << n)-1) {
    vector<int> p(m, 0);
    rep(j, 0, n-1) if(i & (1<<j)) {
      rep(k, 0, m-1) p[k] += ss[k][j];
    }
    bool all = true;
    rep(k, 0, m-1) {
      if(p[k]%2 != pp[k]) {
        all = false;
        break;
      }
    }
    if(all) ans++;
  }
  cout << ans << endl;
}