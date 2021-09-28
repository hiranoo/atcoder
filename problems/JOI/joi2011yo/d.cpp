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
  vector<int> nums(n+1); nums[0] = 0;
  rep(i, 1, n) cin >> nums[i];

  vector< vector<ull> > dp(n+1, vector<ull>(21, 0));
  dp[0][0] = 1;

  rep(i, 1, n) rep(j, 0, 20) {
    if(i==1 && nums[i]==0) dp[i][j] += dp[i-1][j];
    else{
      if(j + nums[i] <= 20) dp[i][j + nums[i]] += dp[i-1][j];
      if(j - nums[i] >= 0) dp[i][j - nums[i]] += dp[i-1][j];
    }
  }

  // cout << "  "; rep(i, 0, n) cout << i << " "; cout << endl;
  // cout << "------------------------------------------" << endl;
  // rep(j, 0, 20) {
  //   cout << j << " "; rep(i, 0, n) cout << dp[i][j] << " "; cout << endl;
  // }
  cout << dp[n-1][nums[n]] << endl;
}