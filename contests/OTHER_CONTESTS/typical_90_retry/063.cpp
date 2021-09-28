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
// const ll INF = 1e16;
const int INF = 1001001001;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int h, w; cin >> h >> w;
  vector<vector<int>> p(h, vector<int>(w));
  rep(i, 0, h-1) rep(j, 0, w-1) cin >> p[i][j];
  
  int ans = 0;
  rep(s, 0, (1<<h)-1) {
    int A = 0;
    int C = -1;
    rep(i, 0, h-1) if(s>>i & 1) A++;

    vector<int> num(h*w+5, 0);
    rep(j, 0, w-1) {
      bool ok = true;
      int v = -1;
      rep(i, 0, h-1) if(s>>i & 1) {
        if(v == -1) v = p[i][j];
        else if(v != p[i][j]) {
          ok = false;
          break;
        }
      }
      if(ok) num[v] += A;
    }
    // if(s==6) for(auto v : num) cout << v << " "; cout << endl;
    int AB = 0;
    for(auto v : num) AB = max(AB, v);
    ans = max(ans, AB);
  }

  cout << ans << endl;
}
