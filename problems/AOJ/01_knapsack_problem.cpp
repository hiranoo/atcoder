#include <iostream>
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
//#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
typedef long long ll;
using namespace std;

int knapsack(int v[], int w[], int N, int W){
  int dp[N+1][W+1];
  rep(i, 0, N-1) dp[i][0]=0;
  rep(i, 0, W) dp[0][i]=0;

  rep(i, 0, N-1){
    rep(j, 0, W){
      if(j < w[i]) dp[i+1][j] = dp[i][j];
      else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
    }
  }
  return dp[N][W];
}

int main(){
  int N, W; cin >> N >> W;
  int v[N], w[N];
   
  rep(i, 0, N-1){
    cin >> v[i] >> w[i];
  }
  
  int ans = knapsack(v, w, N, W);
  cout << ans << endl;
  return 0;
}