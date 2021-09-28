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

ll near(ll a, ll b, ll obj){
  if(abs(a-obj) > abs(b-obj)) return b;
  return a;
}

int main(){
  string a; int K; 
  cin >> a >> K;
  
  vector<int> digit;
  digit.push_back(0);
  for(auto v : a) digit.push_back(v-'0');

  int len = a.size();  

  vector<vector<vector<ll>>> dp(len+1, vector<vector<ll>>(1LL << 10, vector<ll>(3, 0)));

  ll obj = 0;
  for(int i = 1; i <= len; i++){
    obj *= 10;
    obj += digit[i];
    for(int j = 1; j < 1LL << 10; j++){
      if(bitset<10>(j).count() != K) continue;

      if(j & 1 << digit[i]) dp[i][j][0] = 10*dp[i-1][j][0] + digit[i];

      ll ret1, ret2;
      ret1 = 0; ret2 = 0;
      for(int k = 9; k >= 0; k--){
        if(j & 1 << k) {
          ret1 = 10*dp[i-1][j][1] + k;
          break;
        }
      }
      for(int k = digit[i]-1; k >= 0; k--){
        if(j & 1<<k) {
          ret2 = 10*dp[i-1][j][0] + k;
          break;
        }
      }
      dp[i][j][1] = near(ret1, ret2, obj);
      if(dp[i][j][1] >= obj) dp[i][j][1] = 0;

      ret1 = ret2 = 0;
      for(int k = 0; k <= 9; k++){
        if(j & 1<<k){
          ret1 = 10*dp[i-1][j][2] + k;
          break;
        }
      }
      for(int k = digit[i]+1; k <= 9; k++){
        if(j & 1<<k) {
          ret2 = 10*dp[i-1][j][0] + k;
          break;
        }
      }
      dp[i][j][2] = near(ret1, ret2, obj);
      if(dp[i][j][2] <= obj) dp[i][j][2] = 0;
    }
  }
  
  
  ll ans = 0;
  for(int j = 1; j < 1LL << 10; j++){
    ans = near(ans, dp[len][j][0], obj);
    ans = near(ans, dp[len][j][1], obj);
    ans = near(ans, dp[len][j][2], obj);
  }

  // for(int j = 1; j < 1LL << 10; j++) {
  //   if(bitset<10>(j).count() != K) continue;
  //   cout << endl;
  //   for(int k = 0; k <= 9; k++) if(j & 1<<k) cout << k << " "; cout << endl;
  //   cout << "same" << endl; for(int i = 1; i <= len; i++) cout << dp[i][j][0] << endl;
  //   cout << "smaller" << endl; for(int i = 1; i <= len; i++) cout << dp[i][j][1] << endl;
  //   cout << "larger" << endl; for(int i = 1; i <= len; i++) cout << dp[i][j][2] << endl;
  // }
  cout << abs(obj - ans) << endl;
}