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
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  stack<int> stk;
  stk.push(a[0]);
  int ans = 0;
  rep(i, 1, n-1) {
    while(stk.size() && stk.top() > a[i]) {
      ans++;
      stk.pop();
    }
    if(stk.size() && stk.top() < a[i]) stk.push(a[i]);
    if(!stk.size()) stk.push(a[i]);
  }

  ans += stk.size();

  cout << ans << endl;
}