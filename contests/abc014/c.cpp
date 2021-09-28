#include <bits/stdc++.h>
// #include <atcoder/segtree>
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
  vector<ll> sum(1000001, 0);
  rep(i, 1, n) {
    int a, b; cin >> a >> b;
    sum[a]++;
    sum[b+1]--;
  }

  ll ans = 0;
  ll res = 0;
  for(auto s : sum) {
    res += s;
    ans = max(ans, res);
  }
  cout << ans << endl;
}