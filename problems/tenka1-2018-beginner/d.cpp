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

  int t = 1;
  int diff = 2;
  while(t < n) {
    t += diff;
    diff++;
  }
  if(t != n) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  cout << diff << endl;
  diff--;
  // cout << diff << endl;
  vector<vector<int>> memo(diff+1, vector<int>(n+1, 0));
  int top = 0;
  int j = 1;
  rep(i, 1, n) {
    // printf("i:%d, top:%d, top+j: %d\n", i, top, top+j);
    memo[top][i] = 1;
    memo[top+j][i] = 1;
    j++;
    if(top + j > diff) {
      top++;
      j = 1;
    }
  }

  rep(y, 0, diff) {
    cout << diff << " ";
    int cnt = 0;
    rep(x, 1, n) {
      if(memo[y][x]) {
        cout << x;
        cnt++;
        if(cnt == diff) cout << endl;
        else cout << " ";
      }
    }
  }
}