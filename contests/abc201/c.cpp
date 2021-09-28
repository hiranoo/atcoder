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

int sum(vector<int> &a) {
  int ans = 0;
  for(auto v : a) ans += v;
  return ans ;
}

int main() {
  string s; cin >> s;
  vector<int> use(10, 0), ng(10, 0);
  rep(i, 0, s.size()-1) {
    if(s[i] == 'o') use[i] = 1;
    if(s[i] == 'x') ng[i] = 1;    
  }

  if(sum(use) >= 5) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  rep(i, 0, 9) rep(j, 0, 9) rep(k, 0, 9) rep(l, 0, 9) {
    bool ok = true; 
    rep(m, 0, 9) if(use[m] == 1 && (m!=i && m!=j && m!=k && m!=l) ) ok = false;
    if(!ok) continue;
    if(ng[i] + ng[j] + ng[k] + ng[l] > 0) continue;
    // cout << i << j << k << l << endl;
    ans++;
  }
  cout << ans << endl;
}