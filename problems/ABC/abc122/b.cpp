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
  string s; cin >> s;
  int n = s.size();

  int ans = 0;
  rep(i, 0, n-1) {
    rep(j, i, n-1) {
      bool ok = true;
      rep(k, i, j) {
        if(s[k] != 'A' && s[k] != 'G' && s[k] != 'C' && s[k] != 'T') {
          ok = false;
          break;
        }
      }
      if(ok) ans = max(ans, j-i+1);
    }
  }

  cout << ans << endl;
}