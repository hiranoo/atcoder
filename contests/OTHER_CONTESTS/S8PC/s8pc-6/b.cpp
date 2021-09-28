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
  int n; cin >> n;
  vector<ll> a(n), b(n);
  rep(i, 0, n-1) cin >> a[i] >> b[i];

  ll ans = 0;
  rep(i, 0, n-1) ans += abs(a[i] - b[i]);

  sort(all(a));
  sort(all(b));

  ll mid_a, mid_b;
  if(n%2==1) {
    mid_a = a[(n+1)/2-1];
    mid_b = b[(n+1)/2-1];
  }else{
    mid_a = (a[n/2-1] + a[n/2]) / 2;
    mid_b = (b[n/2-1] + b[n/2]) / 2;
  }

  // cout << mid_a << " " << mid_b << endl;
  ll sum1, sum2;
  sum1 = sum2 = 0;
  rep(i, 0, n-1) {
    sum1 += abs(a[i] - mid_a);
    sum2 += abs(b[i] - mid_b);
  }

  ans += sum1 + sum2;
  cout << ans << endl;
}