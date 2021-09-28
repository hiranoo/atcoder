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

int corner(vector<vector<int>> &a, int x, int y) {
  int ans = 0;
  if(!a[y][x]) {
    if(a[y+1][x+1]*a[y+1][x]*a[y][x+1]) ans++;
  }else{
    if(a[y+1][x+1]+a[y+1][x]+a[y][x+1]==0) ans++;
    if(a[y+1][x-1]+a[y+1][x]+a[y][x-1]==0) ans++;
    if(a[y-1][x+1]+a[y-1][x]+a[y][x+1]==0) ans++;
    if(a[y-1][x-1]+a[y-1][x]+a[y][x-1]==0) ans++;

    if(a[y+1][x+1]+a[y+1][x]+a[y][x+1]==2) ans++;
  }
  return ans;
}

int main() {
  int h, w; cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h-1) cin >> a[i];
  vector<vector<int>> area(h, vector<int>(w, 0));
  rep(y, 0, h-1) rep(x, 0, w-1) {
    if(a[y][x] == '#') area[y][x] = 1;
  }

  int ans = 0;
  rep(y, 1, h-2) rep(x, 1, w-2) ans += corner(area, x, y);

  cout << ans << endl;
}