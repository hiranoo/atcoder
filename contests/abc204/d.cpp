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
#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
#define INF 1000000


int myceil(float t){
  return (int)ceil(t);
}

int main(){
  int n; cin >> n;
  vector<int> t(n);
  int total = 0;
  rep(i, 0, n-1){
    cin >> t[i];
    total += t[i];
  }
  sort(all(t), greater<int>());

  vector<vector<bool>> dp(n+1, vector<bool>(100000, false));
  rep(i, 0, n-1) dp[i][0] = true;

  rep(i, 0, n-1){
    rep(j, 0, total){
      if(j >= t[i]) dp[i+1][j] = dp[i][j-t[i]] | dp[i][j];
      else dp[i+1][j] = dp[i][j];
    }
  }
  
  int half = total/2;
  if(total%2 == 1) half++;

  
  rep(j, half, total){
    if(dp[n][j]){
      cout << j << endl;
      return 0;
    }
  }

/*
  rep(i, 0, n-1){
    rep(j, 0, total){
      if(dp[i][j]) cout << "1 ";
      else cout << "0 ";
    }cout << endl;
  }
*/

  return 0;
}