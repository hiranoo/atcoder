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
const ll INF = 1e18;

int main() {
  int n; cin >> n;
  vector<ll> a(n), b(n);
  rep(i, 0, n-1) cin >> a[i] >> b[i];

  ll total_a = 0;
  for(auto v : a) total_a += v;

  vector<ll> c(n);
  rep(i, 0, n-1) c[i] = 2*a[i]+b[i];

  sort(all(c));
  reverse(all(c));

  ll sum = 0;
  rep(i, 1, n) {
    sum += c[i-1];
    if(sum > total_a) {
      cout << i << endl;
      return 0;
    }
  }
}