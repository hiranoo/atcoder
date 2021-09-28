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
typedef pair<ll, int> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(m));
  rep(i, 0, n-1) rep(j, 0, m-1) cin >> a[i][j];

  vector<ll> sum(m, 0);
  //rep(i, 0, m-1) rep(j, 0, n-1) sum[i] += a[j][i];

  ll ans = 0;
  rep(t1, 0, m-1) {
    rep(t2, t1+1, m-1) {
      ll sum = 0;
      rep(k, 0, n-1) {
        sum += max(a[k][t1], a[k][t2]);
      }
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
}