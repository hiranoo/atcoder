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
const ll MOD = 1e9+7;


int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(y, 0, h-1) rep(x, 0, w-1) cin >> a[y][x];

  vector<int> col(w, 0), row(h, 0);
  rep(x, 0, w-1) rep(y, 0, h-1) col[x] += a[y][x];
  rep(y, 0, h-1) rep(x, 0, w-1) row[y] += a[y][x];

  rep(y, 0, h-1) rep(x, 0, w-1) {
    int ret = col[x] + row[y] - a[y][x];
    if(x == w-1) cout << ret << endl;
    else cout << ret << " ";
  }
}