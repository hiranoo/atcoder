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

int max_x = 0;

void grundy(vector<int> &ans, vector<int> &a) {
  rep(j, 0, max_x) {
    set<int> s;
    for(auto v : a) if(j-v >= 0) s.insert(ans[j-v]);
    int g = 0;
    while (s.count(g) > 0) g++;
    ans[j] = g;
  }
}

int main() {
  int n, k; cin >> n >> k;
  vector<int> x(n), a(k);
  rep(i, 0, k-1) cin >> a[i];
  rep(i, 0, n-1) cin >> x[i];

  for(auto v : x) max_x = max(max_x, v);
  vector<int> grundy_num(max_x+1);
  grundy(grundy_num, a);  
  
  int ans = 0;
  for(auto v : x) ans ^= grundy_num[v];
  if(ans > 0) cout << "Alice" << endl;
  else cout << "Bob" << endl;
}