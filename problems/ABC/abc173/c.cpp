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
  int h, w, k; cin >> h >> w >> k;
  vector<vector<int>> a(h, vector<int>(w, 0));
  rep(i, 0, h-1) {
    string s; cin >> s;
    rep(j, 0, w-1) {
      if(s[j] == '#') a[i][j] = 1;
    }
  }

  ll ans = 0;
  rep(sh, 0, (1<<h)-1) {
    rep(sw, 0, (1<<w)-1) {
      vector<vector<int>> black = a;
      rep(i, 0, h-1) if(sh & 1<<i) rep(j, 0, w-1) black[i][j] = 0;
      rep(j, 0, w-1) if(sw & 1<<j) rep(i, 0, h-1) black[i][j] = 0;

      int sum = 0;
      rep(i, 0, h-1) rep(j, 0, w-1) sum += black[i][j];
      if(sum == k) ans++;
    }
  }

  cout << ans << endl;
}