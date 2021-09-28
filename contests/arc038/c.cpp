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
const int INF = 1001001001;

vector<int> c(103), a(103), G(103, -1);

int grundy(int i) {
  // if(a[i]%2==0) return 0;
  if(G[i] != -1) return G[i];
  set<int> s;
  rep(j, i-c[i], i-1) s.insert(grundy(j));
  
  int g = 0;
  while(s.count(g) > 0) g++;
  return G[i] = g;
}

int main() {
  int n; cin >> n;
  rep(i, 1, n-1) cin >> c[i] >> a[i];

  int ans = 0;
  rep(i, 1, n-1) ans ^= (a[i]%2)*grundy(i);
  if(ans > 0) cout << "First" << endl;
  else cout << "Second" << endl;
}