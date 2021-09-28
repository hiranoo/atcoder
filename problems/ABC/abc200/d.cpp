#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template<class T> inline bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;
const ll INF = 1e18;

void output(vector<int> &a) {
  cout << a.size();
  for(auto v : a) {
    cout << " " << v;
  }
  cout << endl;
}

// int main() {
//   int n; cin >> n;
//   vector<ll> a(n);
//   rep(i, 0, n-1) cin >> a[i];

//   map<int, vector<int>> mp;

//   rep(s, 1, (1 << min (n, 8))-1) {
//     ll sum = 0;
//     rep(i, 0, min(n, 8)-1) if(s & 1<<i) {
//       sum = (sum + a[i]) % 200;
//     }
//     sum = (sum + 200) % 200;
//     mp[sum].push_back(s);
//   }

//   for(auto itr : mp) {
//     if(itr.second.size() >= 2) {
//       cout << "Yes" << endl;

//       vector<int> b, c;
//       rep(i, 0, min(n, 8)-1) if(itr.second[0] & 1 << i) b.push_back(i+1);
//       rep(i, 0, min(n, 8)-1) if(itr.second[1] & 1 << i) c.push_back(i+1);

//       output(b);
//       output(c);

//       return 0;
//     }
//   }
//   cout << "No" << endl;
// }

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  vector<vector<ll>> dp(n+1, vector<ll>(200, 0));
  dp[0][0] = 1;

  rep(i, 0, n-1) rep(j, 0, 199) {
    dp[i+1][j] += dp[i][j];

    int k = (j - a[i]%200 + 200) % 200; 
    dp[i+1][j] += dp[i][k];
    if(dp[i+1][j] >= 2) {
      vector<int> b, c;
      
      int cj = j;
      for(int ci = i+1; ci > 0; ci--) {
        if(dp[ci][cj] == dp[ci-1][cj]) continue;
        if(dp[ci-1][cj] == 0) {
          b.push_back(ci);
          cj = (cj - a[ci-1]%200 + 200) % 200;
          if(cj == 0) break;
        }
      }

      cj = j;
      for(int ci = i+1; ci > 0; ci--) {
        int ck = (cj - a[ci-1]%200 + 200) % 200;
        if(dp[ci-1][ck] > 0) {
          c.push_back(ci);
          cj = ck;
          if(cj == 0) break;
        }
      }

      // rep(i, 0, 5) cout << dp[i][175] << endl;
      reverse(all(b));
      reverse(all(c));

      cout << "Yes" << endl;
      output(b);
      output(c);
      return 0;
    }
  }

  cout << "No" << endl;
}
