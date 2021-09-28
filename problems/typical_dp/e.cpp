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
const double EPS = 0.0001;

const ll INF = 1000000000;

int main(){
  int d; cin >> d;
  string n_str; cin >> n_str;

  vector<int> digit;
  digit.push_back(0);
  for(auto d : n_str){
    int d_num = d - '0';
    digit.push_back(d_num);
  }

  //for(auto v : digit) cout << v << " "; cout << endl;
  int len = n_str.size();
  
  vector<vector<vector<vector<ll>>>> dp(len+1, vector<vector<vector<ll>>>(2, vector<vector<ll>>(2, vector<ll>(d, 0))));
  dp[0][0][1][0] = 1;
  
  /* 39215 */
  for(int i = 1; i <= len; i++){
    
    for(int j = 0; j < d; j++) {
      /* 32??? */
      for(int k = 0; k <= 9; k++) {
        dp[i][1][1][(j+k)%d] += dp[i-1][1][1][j];
        dp[i][1][1][(j+k)%d] %= MOD;
      }

      /* 39??? ?<2 */
      for(int k = 0; k < digit[i]; k++) {
        dp[i][1][1][(j+k)%d] += dp[i-1][0][1][j];
        dp[i][1][1][(j+k)%d] %= MOD;
      }
      
      /* 39??? ?=2 */
      dp[i][0][1][(j+digit[i])%d] += dp[i-1][0][1][j];
      dp[i][0][1][(j+digit[i])%d] %= MOD;

      /* 00??? ?=0 */
      //dp[i][0][0][j] += dp[i-1][0][0][j];

      /* 00??? ?>0 */
      for(int k = 1; k <= 9; k++) {
        dp[i][1][1][(j+k)%d] += dp[i-1][1][0][j];
        dp[i][1][1][(j+k)%d] %= MOD;
      }
    }
  }

  cout << (dp[len][0][1][0] + dp[len][1][1][0] - 1) % MOD << endl;
}