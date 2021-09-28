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
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  set<int> nums;
  rep(i, 0, (1<<n)) {
    int sum = 0;
    rep(j, 0, n-1) if(i & (1<<j)) {
      sum += a[j];
    }
    nums.insert(sum);
  }

  int q; cin >> q;
  rep(i, 0, q-1) {
    int m; cin >> m;
    if(nums.count(m) > 0) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}