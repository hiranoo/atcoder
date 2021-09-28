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

ll calc_ok(ll n){
  vector<int> digit;
  int i = 0;
  while(n > 0){
    digit.push_back(n%10);
    n /= 10;
  }digit.push_back(0);
  reverse(all(digit));
  
  int d_num = digit.size();

  vector< vector< vector<ll> > > dp(d_num, vector<vector<ll>>(2, vector<ll>(2, 0)));
  dp[0][0][1] = 1;

  /* n = 8425 */
  for(int i = 1; i < d_num; i++){
    /* 842? ?=5 */
    if(digit[i] != 4 && digit[i] != 9) dp[i][0][1] += dp[i-1][0][1];
    
    /* 000? ?=0 */
    if(digit[i] != 4 && digit[i] != 9) dp[i][1][0] += dp[i-1][1][0];

    /* 015? */
    for(int j = 0; j <= 9; j++) {
      if(j == 4 || j == 9) continue;
      dp[i][1][1] += dp[i-1][1][1];
    }

    /* 000? ?>0 */
    for(int j = 1; j <= 9; j++) {
      if(j == 4 || j == 9) continue;
      dp[i][1][1] += dp[i-1][1][0];
    }

    /* 842? ?<5 */
    for(int j = 0; j < digit[i]; j++) {
      if(j == 4 || j == 9) continue;
      dp[i][1][1] += dp[i-1][0][1];
    }
  }

  return dp[d_num-1][0][1] + dp[d_num-1][1][1];


  



  
}

int main(){
  ll a, b; cin >> a >> b;
  ll ans = b - a + 1 - calc_ok(b) + calc_ok(a-1);
  cout << ans << endl;
}