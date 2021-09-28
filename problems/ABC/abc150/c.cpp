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
  vector<int> p(n), q(n);
  rep(i, 0, n-1) {
    int v; cin >> v; v--;
    p[i] = v;
  }
  rep(i, 0, n-1) {
    int v; cin >> v; v--;
    q[i] = v;
  }

  vector<int> idx(n);
  rep(i, 0, n-1) idx[i] = i;
  map<vector<int>, int> mp;
  int cnt = 0;
  do {
    mp[idx] = cnt++;
  } while(next_permutation(all(idx)));

  int ans = abs(mp[p] - mp[q]);
  cout << ans << endl;
}