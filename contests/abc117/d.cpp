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
  int n; ll k; cin >> n >> k;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];

  sort(all(a));
  reverse(all(a));

  vector<int> digit;
  rep(i, 0, 40) {
    if(k & 1LL << i) digit.push_back(1);
    else digit.push_back(0);
  }

  vector<vector<int>> aa(n, vector<int>(41, 0));
  rep(j, 0, n-1) rep(i, 0, 40) {
    if(a[j] & 1LL << i) aa[j][i] = 1;
  }

  bool less = false;
  vector<int> x(41, 0);
  for(int i = 40; i >= 0; i--) {
    if(!less && digit[i] == 0) continue;

    int cnt = 0;
    for(int j = 0; j < n; j++) {
      if(aa[j][i] == 1) cnt++;
    }

    if(cnt*2 < n) x[i] = 1;
    else less = true;
  }

  ll ans = 0;
  for(int i = 40; i >= 0; i--) {
    int cnt = 0;
    for(int j = 0; j < n; j++) {
      if(aa[j][i] == 1) cnt++;
    }

    if(x[i] == 0) ans += (1LL << i) * cnt;
    else ans += (1LL << i) * (n - cnt);
  }

  // for(int i = 40; i>=0; i--) cout << x[i]; cout << endl;
  // for(int j = 0; j < n; j++) {
  //   for(int i = 40; i>=0; i--) cout << aa[j][i];
  //   cout << endl;  
  // }


  cout << ans << endl;
}