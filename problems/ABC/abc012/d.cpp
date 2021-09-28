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
  int n, m; cin >> n >> m;
  vector<vector<ll>> cost(n, vector<ll>(n, INF));
  rep(i, 0, n-1) cost[i][i] = 0;
  rep(i, 0, m-1) {
    int a, b; ll t; cin >> a >> b >> t;
    a--; b--;
    cost[a][b] = cost[b][a] = t;
  }

  rep(k, 0, n-1) rep(i, 0, n-1) rep(j, 0, n-1) {
    cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
  }

  int ans_v = 0; ll ans_cost = INF;
  rep(i, 0, n-1) {
    int v=0; ll c = 0;
    rep(j, 0, n-1) {
      if(cost[i][j] > c) {
        v = j; c = cost[i][j];
      }
    }
    if(ans_cost > c) {
      ans_v = v; ans_cost = c;
    }
  }

  cout << ans_cost << endl;
}
