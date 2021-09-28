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

void f(vector<int> &a, vector<int> &area) {
  int n = a.size();

  stack<pii> stk;
  stk.push(pii(0, -1));

  rep(i, 0, n-1) {
    while(stk.top().first >= a[i]) {
      stk.pop();
    }
    area[i] += i - stk.top().second - 1;
    stk.push(pii(a[i], i));
  }
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];
  
  vector<int> area(n, 1);
  f(a, area);
  reverse(all(a));
  reverse(all(area));
  f(a, area);

  // for(int i = n-1; i >= 0; i--) cout << area[i] << " "; cout << endl;

  int ans = 0;
  rep(i, 0, n-1) {
    ans = max(ans, area[i]*a[i]);
  }
  cout << ans << endl;
}