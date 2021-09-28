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
typedef pair<ll, int> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main() {
  int h, w; cin >> h >> w;
  vector<vector<int>> cost(10, vector<int>(10));
  rep(i, 0, 9) rep(j, 0, 9) cin >> cost[i][j];
  vector<int> counter(10, 0);
  rep(y, 0, h-1) rep(x, 0, w-1) {
    int a; cin >> a;
    if(a == -1 || a == 1) continue;
    counter[a]++;
  }

  rep(k, 0, 9) rep(i, 0, 9) rep(j, 0, 9) {
    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
  }

  int ans = 0;
  rep(i, 0, 9) {
    ans += counter[i] * cost[i][1];
  }
  cout << ans << endl;
}