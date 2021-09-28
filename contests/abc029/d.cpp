#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
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


int main(){
  string n_str; cin >> n_str;
  
  vector<int> digit;
  digit.push_back(0);
  for(auto v : n_str) digit.push_back(v);

  int len = n_str.size();

  int dp[len+1][2][2][10];
  rep(i, 0, len) rep(j, 0, 1) rep(k, 0, 1) rep(l, 0, 9) dp[i][j][k][l] = 0;
  dp[0][0][1][0] = 1;

  ll ans = 0;

  rep(i, 1, len) {
    rep(j, 0, 9){
      if(digit[i] == 1) dp[i][0][1][j+1] += dp[i-1][0][1][j];
      else dp[i][0][1][j] += dp[i-1][0][1][j];

      rep(k, 0, digit[i]-1){
        if(k == 1) dp[i][1][1][j+1] += dp[i-1][0][1][j];
        else dp[i][1][1][j] += dp[i-1][0][1][j];
      }
      rep(k, 1, 9){
        if(k == 1) dp[i][1][1][j+1] += dp[i-1][1][0][j];
        else dp[i][1][1][j] += dp[i-1][1][0][j];
      }
      rep(k, 0, 9){
        if(k == 1) dp[i][1][1][j+1] += dp[i-1][1][1][j];
        else dp[i][1][1][j] += dp[i-1][1][1][j];
      }
    }
  }

  rep(i, 1, len) {
    cout << i << endl;
    rep(j, 0, 2){
      cout << " " << j << endl;
      cout << "  same, non-zero:" << dp[i][0][1][j] << endl;
      cout << "  less, zero:    " << dp[i][1][0][j] << endl;
      cout << "  less, non-zero:" << dp[i][1][1][j] << endl;
    }
  }

  rep(j, 1, 9) ans += j * (dp[len][0][1][j] + dp[len][1][1][j]);

  cout << ans << endl;

}