#include <bits/stdc++.h>
#include <atcoder/all>
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
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int h, w, m; cin >> h >> w >> m;
  vector<pii> bom(m);
  vector<int> cnt_y(h, 0), cnt_x(w, 0);
  rep(i, 0, m-1) {
    int y, x; cin >> y >> x; y--, x--;
    bom[i] = pii(y, x);
    cnt_y[y]++;
    cnt_x[x]++;
  }

  map<pii, int> is_bom;
  for(auto b : bom) is_bom[b]++;

  vector<int> max_y, max_x;
  
  int ma_y = 0, ma_x = 0;
  rep(y, 0, h-1) chmax(ma_y, cnt_y[y]);
  rep(x, 0, w-1) chmax(ma_x, cnt_x[x]);

  rep(y, 0, h-1) if(cnt_y[y] == ma_y) max_y.push_back(y);
  rep(x, 0, w-1) if(cnt_x[x] == ma_x) max_x.push_back(x);

  if(((ll)max_y.size()) * ((ll)max_x.size()) > 300005) {
    cout << ma_y + ma_x << endl;
    return 0;
  }

  bool none = false;
  for(auto y : max_y) for(auto x : max_x) {
    if(is_bom.count(pii(y, x)) == 0) {
      none = true;
      break;
    }
  }

  if(none) cout << ma_y + ma_x << endl;
  else cout << ma_y + ma_x - 1 << endl;
}