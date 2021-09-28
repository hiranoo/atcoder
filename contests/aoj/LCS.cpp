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

int lcs(string a, string b){
  //cout << "\na:" << a << " b:" << b << endl;
  int A = a.size();
  int B = b.size();
  int dp[A+1][B+1];
  rep(i, 0, A) dp[i][0]=0;
  rep(j, 0, B) dp[0][j]=0;

  rep(i, 0, A-1) rep(j, 0, B-1){
    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
    if(a[i]==b[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
  }

  return dp[A][B];
}

int main(){
  int n; cin >> n;
  int ans[n] = {0};

  string a, b;
  rep(i, 0, n-1){
    cin >> a;
    cin >> b;
    ans[i] = lcs(a, b);
  }
  
  rep(i, 0, n-1){
    cout << ans[i] << endl;
  }
  return 0;
}