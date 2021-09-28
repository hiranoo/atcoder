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
// typedef pair<ll, int> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main() {
  int r, c; cin >> r >> c;
  vector<vector<int>> s(r, vector<int>(c, 0));
  rep(i, 0, r-1) rep(j, 0, c-1) cin >> s[i][j];

  int ans = 0;
  rep(i, 0, (1<<r)-1) {
    int sum = 0;
    rep(k, 0, c-1) {
      int head = 0;
      rep(j, 0, r-1) {
        if(i & (1<<j)) head += (1-s[j][k]);
        else head += s[j][k];
      }
      sum += max(head, r-head);
    }
    ans = max(ans, sum);
  }

  cout << ans << endl;
}