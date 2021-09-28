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

int main() {
  int n; cin >> n;
  string s; cin >> s;

  string t = "000";
  ll ans = 0;
  rep(i, 0, 9) {
    t[0] = '0'+i;
    rep(j, 0, 9) {
      t[1] = '0'+j;
      rep(k, 0, 9) {
        t[2] = '0'+k;
        int cur = 0;
        for(auto c : s) {
          if(t[cur] == c) cur++;
          if(cur >= 3) break;
        }
        if(cur >= 3) ans++;
      }
    }
  }

  cout << ans << endl;
}